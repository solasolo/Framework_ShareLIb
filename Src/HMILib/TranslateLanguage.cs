using System;
using System.Collections.Generic;

namespace GLEO.MES.Sys
{
    public enum LanguageType
    {
        Chinese = 0,
        English,
        Germany,
        Japanese,
    }

    public interface IDBLanguageTranslator
    {
        Dictionary<string, string[]> LoadDictionary();
        bool CreateLanguageKey(string key);
    }

    /// <summary>
    ///
    /// Author Gk
    /// Date   2013.10.23
    /// Version 1.0
    /// 
    /// 多语言支持使用方法
    /// 程序入口处
    /// 1创建数据库对象BaseDbSupport的子类对象
    /// 2创建ContentProvider并设置数据库对象
    /// 3本类对象设置ContentProvider
    /// 4初始化
    /// </summary>
    public class TranslateLanguage
    {
        private Dictionary<string, string[]> _Dictionary;

        #region 单例
        private static TranslateLanguage _Instance;

        public static TranslateLanguage Instance
        {
            get
            {
                if (_Instance == null)
                {
                    _Instance = new TranslateLanguage();
                }

                return _Instance;
            }
        }
        #endregion

        #region 设置字典提供者
        
        private IDBLanguageTranslator _Content;//提供字典

        public void SetContentProvider(IDBLanguageTranslator content)
        {
            this._Content = content;
        }

        #endregion

        #region 语言类型
        private LanguageType _CurrentLang;//当前语言
        
        public LanguageType CurrentLang
        {
            get 
            { 
                return _CurrentLang; 
            }

            set 
            { 
                _CurrentLang = value; 
            }
        }
        #endregion

        private TranslateLanguage()
        {
            _CurrentLang = LanguageType.Chinese;
            _Dictionary = null;
        }

        public void Reload()
        {
            if (this._Content != null)
            {
                _Dictionary = this._Content.LoadDictionary();
            }
        }
        /// <summary>
        /// 翻译方法
        /// 在字典中找到后返回
        /// 找不到则orginallang插入到数据库
        /// </summary>
        /// <param name="orginallang">DefaultText的值</param>
        /// <returns></returns>
        public string doTranslate(string orginallang)
        {
            //遍历查字典 
            string Result = "";

            if (_Dictionary == null)
            {
                this.Reload();
            }

            if (_Dictionary != null)
            {
                if (!string.IsNullOrEmpty(orginallang))
                {
                    if (_Dictionary.ContainsKey(orginallang))
                    {
                        string[] temp;
                        _Dictionary.TryGetValue(orginallang, out temp);

                        Result = temp[(int)_CurrentLang];
                    }
                    else
                    {
                        _Dictionary.Add(orginallang, new string[4]);

                        this._Content.CreateLanguageKey(orginallang);
                    }
                }

                if (String.IsNullOrEmpty(Result))
                {
                    Result = orginallang;
                }
            }

            return Result;
        }
    }
}
