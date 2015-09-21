/*Core File */
var GLOBAL = window;

function USING(NamespaceName) {
    var NameList = NamespaceName.split(".");

    var Context = GLOBAL;

    for (var i = 0; i < NameList.length; i++) {
        if (typeof (Context[NameList[i]]) == "undefined") {
            Context[NameList[i]] = new Object();
        }

        Context = Context[NameList[i]];
    }

    return Context;
}

function IMPORT(ModelName) {
    var SM_NAME = "__RESOURCE_MANAGER+OBJECT__"
    /* Create global object of ScriptManager */

    var rm = window[SM_NAME];
    if (typeof (rm) == "undefined") {
        rm = new gleo.sys.ResourceManager();
        window[SM_NAME] = rm;
        window.ClientObjList = {};
    }

    rm.Load(ModelName);
}

USING("gleo.sys");

//Completion of the class of inherit.
Object.prototype.$Extends = function(BaseClass) {
    var base;

    if (typeof (BaseClass) == "string") {
        var CreateObjStr = " new " + BaseClass + "(";

        for (var i = 1; i < arguments.length; i++) {
            CreateObjStr += "arguments[" + i + "]";

            if (i < arguments.length - 1) {
                CreateObjStr += ",";
            }
        }

        CreateObjStr += ");";
        base = eval(CreateObjStr);
    }
    else
        if (typeof (BaseClass) == "function") {
        base = new BaseClass(arguments[1], arguments[2], arguments[3], arguments[4], arguments[5], arguments[6], arguments[7], arguments[8]);
    }

    for (var key in base) {
        if (key == "res") {
            for (var k in base.res) {

                if (!(this.res[k])) {
                    this.res[k] = base.res[k];
                }
            }
        }
        else
            if (!this[key]) {
            this[key] = base[key];
        }
    }
};

/* 实现对象函数转化为事件函数 */
Object.prototype.$CreateEvent = function(func) {
    var me = this;
    var args = Array.prototype.slice.call(arguments, 1); // 获得argumetns中下标为1起的所有参数到一个新数组
    return function() {
        func.apply(me, args);
    };
};

Array.prototype.IndexOf = function(value) {
    var index = -1;
    if (this.length == 0) {
        index = -1;
    }
    else {
        var count = 0;
        var i = 0;
        for (i = 0; i < this.length; i++) {
            if (value == this[i]) {
                break;
            }
            count++;
        }
        if (count < this.length) {
            index = i;
        }
    }
    return index;
};

Array.prototype.Clear = function() {
    if (this.length == 0) {
        return;
    }

    while (this.length > 0) {
        this.pop();
    }
};

/**
* 时间对象的格式化;
* @param {String} format: "Y-MM-dd hh:mm:ss"
*/
Date.prototype.format = function(format) {
    var o = {
        "Y+": this.getYear(), // year
        "M+": this.getMonth() + 1, // month
        "d+": this.getDate(), // day
        "h+": this.getHours(), // hour
        "m+": this.getMinutes(), // minute
        "s+": this.getSeconds(), // second
        "q+": Math.floor((this.getMonth() + 3) / 3), // quarter
        "S": this.getMilliseconds()    // millisecond
    };

    if (/(y+)/.test(format)) {
        format = format.replace(RegExp.$1, (this.getFullYear() + "").substr(4 - RegExp.$1.length));
    }
    for (var k in o) {
        if (new RegExp("(" + k + ")").test(format)) {
            format = format.replace(RegExp.$1, RegExp.$1.length == 1 ? o[k] : ("00" + o[k]).substr(("" + o[k]).length));
        }
    }
    return format;
};

function $(elementId) {
    return document.getElementById(elementId);
}

function $$(tagName) {
    return document.createElement(tagName);
}

//
// gleo.sys.ResourceManager 
//
(function() {
    var _ResourceManager = function() {
        this.ScriptList = new Array();
    };

    function AppendScriptRecource(Receiver, ScriptName, lang) {
        this.Receiver = Receiver;
        this.ScriptName = ScriptName;

        this.Excute = function(ResponseObj) {
            var response = ResponseObj.responseText;
            var Obj = eval(response);

            if (lang == null || lang == undefined) {
                this.Receiver.ScriptList.push(this.ScriptName);
            }
            else {
                var o = window.ClientObjList[this.ScriptName];
            }
        }
    };

    function hasFile(tag, url) {
        var contains = false;
        var files = document.getElementsByTagName(tag);
        var type = tag == "script" ? "src" : "href";

        for (var i = 0, len = files.length; i < len; i++) {
            if (files[i].getAttribute(type) == url) {
                contains = true;
                break;
            }
        }

        return contains;
    };

    function FileExt(url) {
        var att = url.split('.');
        var ext = att[att.length - 1].toLowerCase();
        return ext;
    };

    function Load(element) {
        var head = document.getElementsByTagName("head")[0];
        head.appendChild(element);

        var callback = function() { };

        if (Browser.Type.ie) {
            element.onreadystatechange = function() {
                if (this.readyState == 'loaded' || this.readyState == 'complete') {
                    callback();
                }
            };
        } else if (Browser.Type.gecko) {
            element.onload = function() {
                callback();
            };
        } else {
            callback();
        }
    };

    function LoadCss(file) {
        if (!hasFile("link", file)) {
            var cssFile = document.createElement("link");
            cssFile.setAttribute('type', 'text/css');
            cssFile.setAttribute('rel', 'stylesheet');
            cssFile.setAttribute('href', file);

            Load(cssFile);
        }
    };

    function LoadScript(file) {
        if (!hasFile("script", file)) {
            var script = document.createElement("script");
            script.setAttribute('charset', 'utf-8');
            script.setAttribute('type', 'text/javascript');
            script.setAttribute('src', file);

            Load(script);
        }
    };

    _ResourceManager.prototype.Load = function(file) {
        var ext = FileExt(file);

        switch (ext) {
            case "css":
                LoadCss(this.GetURL("link", file));
                break;

            case "js":
                LoadScript(this.GetURL("script", file));
                break;
        }
    };

    _ResourceManager.prototype.GetScript = function(ScriptName, lang) {
        if (this.IsInClient(ScriptName)) {
            if (lang == null || lang == undefined) {
                return;
            }
        }

        var Me = this;
        var request = new gleo.sys.AJAXRequest();
        request.URL = this.GetURL(ScriptName, lang);
        request.Async = false;
        request.Content = "";

        request.CallBack = new AppendScriptRecource(this, ScriptName, lang);

        request.Post();
    };

    _ResourceManager.prototype.IsInClient = function(ScriptName) {
        var IsIn = false;

        for (var i = 0; i < this.ScriptList.length; i++) {
            if (ScriptName == this.ScriptList[i]) {
                IsIn = true;
                break;
            }
        }

        return IsIn;
    };

    _ResourceManager.prototype.GetURL = function(type, file, lang) {
        var path = file;
        var tags = document.getElementsByTagName(type);
        var arrt = type == "script" ? "src" : "href";

        for (var i = 0, len = tags.length; i < len; i++) {
            url = tags[i].getAttribute(arrt).toLowerCase();
            if (/^.+\/core\.js$/i.test(url)) {
                path = url.replace(/core\.js/, file);
                break;
            }
        }
        return path;
    }

    _ResourceManager.prototype.TranslateJustInTime = function(lang) {
        for (var i = 1; i < this.ScriptList.length; i++) {
            this.GetScript(this.ScriptList[i], lang);
        }
    };

    gleo.sys.ResourceManager = _ResourceManager;
})();

(function() {
    Debugger = {
        Write: function(s, e) {
            var Message = s;
            if (e) {
                Message += "\r\n" + e.message ? e.message : e;

                if (arguments.length > 2) {
                    appends = Array.prototype.slice.call(arguments, 2);
                    Message += "\r\n" + appends.join("\r\n");
                }

                alert(Message);
            }
        }
    };
})();

/**
* Sys
*/
(function() {
    var rtrim = /^(\s|\u00A0)+|(\s|\u00A0)+$/g, // Used for trimming whitespace
 	rnotwhite = /\S/,
 	readyList;

    String.prototype.Trim = function() {
        return (this || "").replace(rtrim, "");
    };

    Date.Now = function() {
        return (new Date).getTime();
    };

    var DOMContentLoaded = function() {
        if (document.readyState === "complete") {
            Sys.DomCompleted = true;
            Event.Remove(document, "DOMContentLoaded", DOMContentLoaded);
            ready();
        }
        else {
            setTimeout(arguments.callee, 13);
        }
    };

    // Handle when the DOM is ready
    var ready = function() {
        // Make sure that the DOM is not already loaded
        if (!Sys.isReady && Sys.DomCompleted) {
            // Make sure body exists, at least, in case IE gets a little overzealous (ticket #5443).
            if (!document.body) {
                setTimeout(Sys.ready, 13);
                return;
            }

            // Remember that the DOM is ready
            Sys.isReady = true;

            // If there are functions bound, to execute
            var i = 0;
            if (readyList) {
                // Execute all of them
                while ((fn = readyList[i++])) {
                    fn.call();
                }

                // Reset the list of functions
                readyList = null;
            }
        }
    };

    var bindReady = function() {
        if (readyList) {
            return;
        }

        readyList = [];

        // Catch cases where $(document).ready() is called after the
        // browser event has already occurred.
        if (document.readyState === "complete") {
            ready();
            return
        }

        // Mozilla, Opera and webkit nightlies currently support this event
        if (document.addEventListener) {
            // Use the handy event callback
            document.addEventListener("DOMContentLoaded", DOMContentLoaded, false);

            // A fallback to window.onload, that will always work
            window.addEventListener("load", ready, false);

            // If IE event model is used
        }
        else
            if (document.attachEvent) {
            // ensure firing before onload,
            // maybe late but safe also for iframes
            document.attachEvent("onreadystatechange", DOMContentLoaded);

            // A fallback to window.onload, that will always work
            window.attachEvent("onload", ready);

            // If IE and not a frame
            // continually check to see if the document is ready
            var toplevel = false;

            try {
                toplevel = window.frameElement == null;
            }
            catch (e) {
            }

            if (document.documentElement.doScroll && toplevel) {
                doScrollCheck();
            }
        }
    };

    // The DOM ready check for Internet Explorer
    var doScrollCheck = function() {
        if (Sys.isReady) {
            return;
        }

        try {
            // If IE is used, use the trick by Diego Perini
            // http://javascript.nwbox.com/IEContentLoaded/
            document.documentElement.doScroll("left");
        } catch (e) {
            setTimeout(doScrollCheck, 1);
            return;
        }

        // and execute any waiting functions
        ready();
    };

    var Delegate = function(args) {
        var obj = args[0];
        var proc = args[1];
        var params = Array.prototype.slice.call(args, 2);

        if (typeof obj == 'function') {
            proc = obj;
            obj = null;
            params = Array.prototype.slice.call(args, 1);
        }

        return function() {
            return proc.apply(obj, params);
        };
    };

    Sys = {
        toString: Object.prototype.toString,

        Startup: function(obj, proc) {
            bindReady();

            var ProcHandle = Delegate(arguments);

            readyList.push(ProcHandle);
            ready();
        },

        Run: function(delay, obj, proc) {
            var time = Array.prototype.shift.call(arguments);
            var ProcHandle = Delegate(arguments);
            var Me = obj;

            var TimeProc = function() {
                if (arguments.callee.Running) {
                    if (ProcHandle.apply()) {
                        window.setTimeout(TimeProc, time);
                    }
                    else {
                        arguments.callee.Running = false;
                    }
                }
            };

            TimeProc.Running = true;
            TimeProc.apply();

            return TimeProc;
        },

        RunLater: function(delay, obj, proc) {
            var time = Array.prototype.shift.call(arguments);
            var ProcHandle = Delegate(arguments);

            window.setTimeout(ProcHandle, time);
        },

        // See test/unit/core.js for details concerning isFunction.
        // Since version 1.3, DOM methods and functions like alert
        // aren't supported. They return false on IE (#2968).
        isFunction: function(obj) {
            return toString.call(obj) === "[object Function]";
        },

        isArray: function(obj) {
            return toString.call(obj) === "[object Array]";
        },

        isPlainObject: function(obj) {
            // Must be an Object.
            // Because of IE, we also have to check the presence of the constructor property.
            // Make sure that DOM nodes and window objects don't pass through, as well
            if (!obj || toString.call(obj) !== "[object Object]" || obj.nodeType || obj.setInterval) {
                return false;
            }

            // Not own constructor property must be Object
            if (obj.constructor &&
            !hasOwnProperty.call(obj, "constructor") &&
            !hasOwnProperty.call(obj.constructor.prototype, "isPrototypeOf")) {
                return false;
            }

            // Own properties are enumerated firstly, so to speed up,
            // if last one is own, then all properties are own.

            var key;
            for (key in obj) {
            }

            return key === undefined || hasOwnProperty.call(obj, key);
        },

        error: function(msg) {
            throw msg;
        },

        // Evalulates a script in a global context
        globalEval: function(data) {
            if (data && rnotwhite.test(data)) {
                var head = document.getElementsByTagName("head")[0] || document.documentElement, script = document.createElement("script");

                script.type = "text/javascript";

                if (Browser.scriptEval) {
                    //                    script.appendChild(document.createTextNode(data));	// FF is ok???
                    script.setAttribute("src", data);
                }
                else {
                    //                    script.text = data;	// is ok??? 
                    script.src = data;
                }

                // Use insertBefore instead of appendChild to circumvent an IE6 bug.
                // This arises when a base node is used (#2709).
                head.insertBefore(script, head.firstChild);
                //                head.removeChild(script);
            }
        },

        // results is for internal usage only
        makeArray: function(array, results) {
            var ret = results || [];

            if (array != null) {
                // The window, strings (and functions) also have 'length'
                // The extra typeof function check is to prevent crashes
                // in Safari 2 (See: #3039)
                if (array.length == null || typeof array === "string" || Sys.isFunction(array) || (typeof array !== "function" && array.setInterval)) {
                    push.call(ret, array);
                }
                else {
                    Sys.merge(ret, array);
                }
            }

            return ret;
        },

        inArray: function(elem, array) {
            if (array.indexOf) {
                return array.indexOf(elem) > -1;
            }

            for (var i = 0, length = array.length; i < length; i++) {
                if (array[i] === elem) {
                    return i > -1;
                }
            }

            return -1;
        },

        merge: function(first, second) {
            var i = first.length, j = 0;

            if (typeof second.length === "number") {
                for (var l = second.length; j < l; j++) {
                    first[i++] = second[j];
                }
            }
            else {
                while (second[j] !== undefined) {
                    first[i++] = second[j++];
                }
            }

            first.length = i;

            return first;
        },

        loadXml: function(xmlStr) {
            var xmlDoc;
            try { //IE
                xmlDoc = new ActiveXObject("Microsoft.XMLDOM");
                xmlDoc.async = "false";
                xmlDoc.loadXML(xmlStr);
            }
            catch (e) {
                try { // Firefox, Mozilla, Opera, etc.
                    parser = new DOMParser();
                    xmlDoc = parser.parseFromString(xmlStr, "text/xml");
                }
                catch (e) {
                    Debugger.Write("Parser XML error: " + xmlStr, e);
                }
            }
            return xmlDoc;
        }
    };
})();

(function() {
    var root = document.documentElement,
    script = document.createElement("script"),
    div = document.createElement("div"),
    div2 = document.createElement("div"),
    id = "script" + Date.Now(),
    fragment = document.createDocumentFragment();

    div.style.display = "none";
    div.innerHTML = "   <link/><table></table><a href='/a' style='color:red;float:left;opacity:.55;'>a</a><input type='checkbox'/>";

    div2.innerHTML = "<input type='radio' name='radiotest' checked='checked'/>";
    fragment.appendChild(div.firstChild);
    div2.style.width = div.style.paddingLeft = "1px";
    //    document.body.appendChild(div2);


    script.type = "text/javascript";
    root.insertBefore(script, root.firstChild);

    var all = div.getElementsByTagName("*"),
    a = div.getElementsByTagName("a")[0];

    // Can't get basic test support
    if (!all || !all.length || !a) {
        return;
    }

    try {
        script.appendChild(document.createTextNode("window." + id + "=1;"));
    }
    catch (e) {
    }

    // Technique from Juriy Zaytsev
    // http://thinkweb2.com/projects/prototype/detecting-event-support-without-browser-sniffing/
    var eventSupported = function(eventName) {
        var el = document.createElement("div");
        eventName = "on" + eventName;

        var isSupported = (eventName in el);
        if (!isSupported) {
            el.setAttribute(eventName, "return;");
            isSupported = typeof el[eventName] === "function";
        }
        el = null;

        return isSupported;
    };

    /**
    * 浏览器版本

    *
    * gecko内核浏览器的版本会转换成这样(如 1.9.0.2 -> 10900).
    *
    * webkit内核浏览器版本号使用其build号 (如 522).
    * @name baidu.editor.browser.version
    * @grammar     baidu.editor.browser.version
    * @return     {Boolean}    返回浏览器版本号
    * @example
    * if ( baidu.editor.browser.ie && <b>baidu.editor.browser.version</b> <= 6 )
    *     alert( "Ouch!" );
    */
    var CheckVersion = function() {
        var version = 0;
        var browser = Browser;

        // Internet Explorer 6.0+
        if (browser.ie) {
            version = parseFloat(agent.match(/msie (\d+)/)[1]);

            /**
            * 检测浏览器是否为 IE8 浏览器

            */
            browser.ie8 = !!document.documentMode;

            /**
            * 检测浏览器是否为 IE8 模式
            */
            browser.ie8Compat = document.documentMode == 8;

            /**
            * 检测浏览器是否运行在 兼容IE7模式
            */
            browser.ie7Compat = ((version == 7 && !document.documentMode)
                    || document.documentMode == 7);

            /**
            * 检测浏览器是否IE6模式或怪异模式
            \            */
            browser.ie6Compat = (version < 7 || browser.quirks);
        }

        // Gecko.
        if (browser.gecko) {
            var geckoRelease = agent.match(/rv:([\d\.]+)/);
            if (geckoRelease) {
                geckoRelease = geckoRelease[1].split('.');
                version = geckoRelease[0] * 10000 + (geckoRelease[1] || 0) * 100 + (geckoRelease[2] || 0) * 1;
            }
        }
        /**
        * 检测浏览器是否为chrome
        */
        if (/chrome\/(\d+\.\d)/i.test(agent)) {
            browser.chrome = +RegExp['\x241'];
        }
        /**
        * 检测浏览器是否为safari
        */
        if (/(\d+\.\d)?(?:\.\d)?\s+safari\/?(\d+\.\d+)?/i.test(agent) && !/chrome/i.test(agent)) {
            browser.safari = +(RegExp['\x241'] || RegExp['\x242']);
        }

        // Opera 9.50+
        if (browser.opera)
            version = parseFloat(opera.version());

        // WebKit 522+ (Safari 3+)
        if (browser.webkit)
            version = parseFloat(agent.match(/ applewebkit\/(\d+)/)[1]);

        return version;
    };

    var agent = navigator.userAgent.toLowerCase(),
        opera = window.opera;

    Browser = {};

    Browser.Type = {
        /**
        * 检测浏览器是否为IE
        */
        ie: !!window.ActiveXObject,

        /**
        * 检测浏览器是否为Opera
        */
        opera: (!!opera && opera.version),

        /**
        * 检测浏览器是否为WebKit内核
        */
        webkit: (agent.indexOf(' applewebkit/') > -1),

        /**
        * 检测是否为Adobe AIR
        */
        air: (agent.indexOf(' adobeair/') > -1),

        /**
        * 检查是否为Macintosh系统
        */
        mac: (agent.indexOf('macintosh') > -1),

        /**
        * 检查浏览器是否为quirks模式
        */
        quirks: (document.compatMode == 'BackCompat')
    };

    Browser.Features = {
        //  
        // Furtures
        //   
        scriptEval: window[id] ? true : false,

        // IE strips leading whitespace when .innerHTML is used
        leadingWhitespace: div.firstChild.nodeType === 3,

        // Make sure that tbody elements aren't automatically inserted
        // IE will insert them into empty tables
        tbody: !div.getElementsByTagName("tbody").length,

        // Make sure that link elements get serialized correctly by innerHTML
        // This requires a wrapper element in IE
        htmlSerialize: !!div.getElementsByTagName("link").length,

        // Get the style information from getAttribute
        // (IE uses .cssText insted)
        style: /red/.test(a.getAttribute("style")),

        // Make sure that URLs aren't manipulated
        // (IE normalizes it by default)
        hrefNormalized: a.getAttribute("href") === "/a",

        // Make sure that element opacity exists
        // (IE uses filter instead)
        // Use a regex to work around a WebKit issue. See #5145
        opacity: /^0.55$/.test(a.style.opacity),

        // Verify style float existence
        // (IE uses styleFloat instead of cssFloat)
        cssFloat: !!a.style.cssFloat,

        // Make sure that if no value is specified for a checkbox
        // that it defaults to "on".
        // (WebKit defaults to "" instead)
        checkOn: div.getElementsByTagName("input")[0].value === "on",

        // Make sure that a selected-by-default option has a working selected property.
        // (WebKit defaults to false instead of true, IE too, if it's in an optgroup)
        optSelected: document.createElement("select").appendChild(document.createElement("option")).selected,

        // WebKit doesn't clone checked state correctly in fragments
        checkClone: fragment.cloneNode(true).cloneNode(true).lastChild.checked,

        parentNode: div.removeChild(div.appendChild(document.createElement("div"))).parentNode === null,

        submitBubbles: eventSupported("submit"),
        changeBubbles: eventSupported("change"),
        boxModel: div.offsetWidth === 2,

        // Test to see if it's possible to delete an expando from an element Fails in Internet Explorer
        deleteExpando: (function() {
            var rt = true;

            try {
                delete script.test;
            }
            catch (e) {
                rt = false;
            }

            return rt;
        })(),

        noCloneEvent: (function() {
            var rt = true;

            if (div.attachEvent && div.fireEvent) {
                div.attachEvent("onclick", function click() {
                    // Cloning a node shouldn't copy over any bound event handlers (IE does this)
                    rt = false;
                    div.detachEvent("onclick", click);
                });
                div.cloneNode(true).fireEvent("onclick");
            }
            root.removeChild(script);

            return rt;
        })()
    };


    /**
    * 检测浏览器是否为Gecko内核，如Firefox
    */
    Browser.Type.gecko = (navigator.product == 'Gecko' && !Browser.Type.webkit && !Browser.Type.opera);

    Browser.Version = CheckVersion();

    /**
    * 是否是兼容模式的浏览器

    */
    Browser.isCompatible = !Browser.Type.mobile && (
            (Browser.Type.ie && Browser.Version >= 6) ||
            (Browser.Type.gecko && Browser.Version >= 10801) ||
            (Browser.Type.opera && Browser.Version >= 9.5) ||
            (Browser.Type.air && Browser.Version >= 1) ||
            (Browser.Type.webkit && Browser.Version >= 522) ||
            false);

    //document.body.removeChild(div).style.display = 'none';

    // release memory in IE
    root = script = div = all = a = null;
})();

///////
(function() {
    Event = {
        /**
        * return event object<br>ie and ff are compatible
        * @return{object} event
        */
        getEvent: function() {
            var e = window.event;
            if (!e) {
                func = arguments.callee.caller;
                while (func != null) {
                    var arg0 = func.arguments[0];
                    if (arg0) {
                        if ((arg0.constructor == Event || arg0.constructor == MouseEvent) ||
                        (typeof (arg0) == "object" && arg0.preventDefault && arg0.stopPropagation)) {
                            e = arg0;
                            break;
                        }
                    }
                    func = func.caller;
                }

                if (e) {
                    e.srcElement = e.target;
                }
            }

            return e;
        },

        /**
        * 跨平台的事件监听函数
        * @param {Node} node 需要监听事件的DOM节点
        * @param {String} eventType 需要监听的事件类型,example:click,mouseover without "on"
        * @param {Function} eventHandle 事件处理函数
        * @return {Function} 返回事件处理函数的引用，用于释放监听
        */
        Add: function(node, eventType, eventHandle) {
            var args;
            if (arguments.length > 3) {
                args = Array.prototype.slice.call(arguments, 3);
            }
            else {
                args = [node];
            }

            var func = eventHandle;
            eventHandle = function() {
                func.apply(this, args);
            };

            if (node.attachEvent) {//IE
                if (eventType.indexOf('on')) {
                    eventType = 'on' + eventType;
                }
                node.attachEvent(eventType, eventHandle);
            }
            else {//FF
                if (!eventType.indexOf('on')) {
                    eventType = eventType.substring(2, eventType.length);
                }

                if (eventType == "mouseenter") eventType = "mouseover";
                if (eventType == "mouseleave") eventType = "mouseout";

                node.addEventListener(eventType, eventHandle, false);
            }
            
            return eventHandle;
        },

        /**
        * 跨平台的事件监听卸载函数
        * @param {Node} node 需要卸载监听事件的DOM节点
        * @param {String} eventType 需要卸载监听的事件类型,example:click,mouseover
        * @param {Function} eventHandle 卸载事件处理函数
        */
        Remove: function(node, eventType, eventHandle) {
            if (node.detachEvent) {
                if (eventType.indexOf('on')) {
                    eventType = 'on' + eventType;
                }
                node.detachEvent(eventType, eventHandle);
            }
            else {
                if (!eventType.indexOf('on')) {
                    eventType = eventType.substring(2, eventType.length);
                }
                node.removeEventListener(eventType, eventHandle, false);
            }
        }
    };
})();
///////
///////
(function() {
    var parseJSON = function(data) {
        if (typeof data !== "string" || !data) {
            return null;
        }

        data = data.Trim();

        // Make sure the incoming data is actual JSON Logic borrowed from http://json.org/json2.js
        // example:[{"a":0},{"b":1}] or {"a":0}
        if (/^[\],:{}\s]*$/.test(data.replace(/\\(?:["\\\/bfnrt]|u[0-9a-fA-F]{4})/g, "@").replace(/"[^"\\\n\r]*"|true|false|null|-?\d+(?:\.\d*)?(?:[eE][+\-]?\d+)?/g, "]").replace(/(?:^|:|,)(?:\s*\[)+/g, ""))) {

            // Try to use the native JSON parser first
            return JSON && JSON.parse ? JSON.parse(data) : (new Function("return " + data))();
        } else {
            throw ("invalid json data: " + data);
        }
    },

    parseXml = function(xmlStr) {
        var xmlDoc;
        try { //IE
            xmlDoc = new ActiveXObject("Microsoft.XMLDOM");
            xmlDoc.async = "false";
            xmlDoc.loadXML(xmlStr);
        } catch (e) {
            try { // Firefox, Mozilla, Opera, etc.
                parser = new DOMParser();
                xmlDoc = parser.parseFromString(xmlStr, "text/xml");
            } catch (e) {
                throw e;
            }
        }
        return xmlDoc;
    };

    Ajax = {
        doGet: function(url) {
            var rq = new gleo.sys.AJAXRequest();
            rq.Async = false;
            rq.URL = url;
            rq.Get();
        },
        doPost: function(url, data, success, error, ctype) {
            //            if (data && Sys.isFunction(data)) {
            //                error = error || success;
            //                success = data;
            //                data = null;
            //            }

            var rq = new gleo.sys.AJAXRequest();

            rq.URL = url;
            rq.CallBack = {
                Excute: function(xhr) {
                    try {
                        data = parseJSON(xhr.responseText);
                    } catch (e) {
                        if (error) {
                            error(e);
                        }
                        else {
                            Debugger.Write("JSON Parse error:", e, xhr.responseText);
                        }
                    }

                    if (success) {
                        success(data);
                    }
                },
                Error: error
            };

            if (!data) {
                rq.Content = null;
            }
            else {
                rq.Content = data;
            }

            return rq.Post("json", ctype);
        },
        getJSON: function(url, data, success, error) {
            //            if (data && Sys.isFunction(data)) {
            //                error = error || success;
            //                success = data;
            //                data = null;
            //            }

            var rq = new gleo.sys.AJAXRequest();

            rq.URL = url;
            rq.CallBack = {
                Excute: function(xhr) {
                    try {
                        data = parseJSON(xhr.responseText);
                    } catch (e) {
                        if (error) {
                            error(e);
                        }
                        else {
                            Debugger.Write("JSON Parse error:", e, xhr.responseText);
                        }
                    }

                    if (success) {
                        success(data);
                    }
                },
                Error: error
            };

            if (!data) {
                rq.Content = null;
            }
            else {
                rq.Content = JSON.stringify(data);
            }

            return rq.Post("json");
        },

        getXml: function(url, data, success, error) {
            if (data && data.call) {
                error = error || success;
                success = data;
                data = null;
            }

            var rq = new gleo.sys.AJAXRequest();

            rq.URL = url;
            rq.CallBack = {
                Excute: function(xhr) {
                    try {
                        data = parseXml(xhr.responseText); // data = xhr.responseXML;	// can't why???
                    } catch (e) {
                        if (error) {
                            error(e);
                        }
                        else {
                            Debugger.Write("Parser XML", e);
                        }
                    }

                    if (success) {
                        success(data);
                    }
                },
                Error: error
            };
            rq.Content = data;
            return rq.Content ? rq.Post("xml") : rq.Get();
        },

        getHtml: function(url, data, success, error) {
            if (Sys.isFunction(data)) {
                error = error || success;
                success = data;
                data = null;
            }

            var rq = new gleo.sys.AJAXRequest();

            rq.URL = url;
            rq.CallBack = {
                Excute: function(xhr) {
                    data = xhr.responseText;
                    if (success) {
                        success(data);
                    }
                },
                Error: error
            };
            rq.Content = data;
            return rq.Content ? rq.Post("html") : rq.Get();
        },

        getScript: function(url) {
            Sys.globalEval(url);
        }
    };
})();

///////
(function() {
    // exclude the following css properties to add px
    var rexclude = /z-?index|font-?weight|opacity|zoom|line-?height/i,
        ralpha = /alpha\([^)]*\)/,
        ropacity = /opacity=([^)]*)/,
        rfloat = /float/i,
        rdashAlpha = /-([a-z])/ig,
        rupper = /([A-Z])/g,
        rnumpx = /^-?\d+(?:px)?$/i,
        rnum = /^-?\d/,
		cssShow = { position: "absolute", visibility: "hidden", display: "block" },
		cssWidth = ["Left", "Right"],
		cssHeight = ["Top", "Bottom"], // cache check for defaultView.getComputedStyle
 		getComputedStyle = document.defaultView && document.defaultView.getComputedStyle, // normalize float css property
 		styleFloat = Browser.Features.cssFloat ? "cssFloat" : "styleFloat",
        fcamelCase = function(all, letter) {
            return letter.toUpperCase();
        };

    var css = function(elem, name, force) {
        var ret, style = elem.style, filter;

        // IE uses filters for opacity
        if (!Browser.Features.opacity && name === "opacity" && elem.currentStyle) {
            ret = ropacity.test(elem.currentStyle.filter || "") ? (parseFloat(RegExp.$1) / 100) + "" : "";

            return ret === "" ? "1" : ret;
        }

        // Make sure we're using the right name for getting the float value
        if (rfloat.test(name)) {
            name = styleFloat;
        }

        if (!force && style && style[name]) {
            ret = style[name];
        }
        else
            if (getComputedStyle) {
            // Only "float" is needed here
            if (rfloat.test(name)) {
                name = "float";
            }

            name = name.replace(rupper, "-$1").toLowerCase();

            var defaultView = elem.ownerDocument.defaultView;

            if (!defaultView) {
                return null;
            }

            var computedStyle = defaultView.getComputedStyle(elem, null);

            if (computedStyle) {
                ret = computedStyle.getPropertyValue(name);
            }

            // We should always get a number back from opacity
            if (name === "opacity" && ret === "") {
                ret = "1";
            }
        }
        else
            if (elem.currentStyle) {
            var camelCase = name.replace(rdashAlpha, fcamelCase);

            ret = elem.currentStyle[name] || elem.currentStyle[camelCase];

            // If we're not dealing with a regular pixel number
            // but a number that has a weird ending, we need to convert it to pixels
            if (!rnumpx.test(ret) && rnum.test(ret)) {
                // Remember the original values
                var left = style.left, rsLeft = elem.runtimeStyle.left;

                // Put in the new values to get a computed value out
                elem.runtimeStyle.left = elem.currentStyle.left;
                style.left = camelCase === "fontSize" ? "1em" : (ret || 0);
                ret = style.pixelLeft + "px";

                // Revert the changed values
                style.left = left;
                elem.runtimeStyle.left = rsLeft;
            }
        }

        return ret;
    };

    /**
    * if the value is undefined, return the style value about specified style name from the specified element, <br/>
    * else set the style value for the specified style name of the specified element, or the second parameter <br/>
    * may be a kv pair without third parameter, like { "color": "green", "background": "gray", "width":"500" }.
    * @param {Object} elem
    * @param {String} name
    * @param {String} value
    */

    Css = {
        /**
        * Read Style
        * @param {Object} elem
        * @param {String} name
        */
        Get: function(elem, name) {
            // don't set styles on text and comment nodes
            if (!elem || elem.nodeType == 3 || elem.nodeType == 8) {
                return undefined;
            }

            // ignore negative width and height values #1599
            if ((name == "width" || name == "height") && parseFloat(value) < 0) {
                value = undefined;
            }

            var style = elem.style || elem;

            // IE uses filters for opacity
            if (!Browser.Features.opacity && name == "opacity") {
                return style.filter && style.filter.indexOf("opacity=") >= 0 ? (parseFloat(ropacity.exec(style.filter)[1]) / 100) + "" : "";
            }

            // Make sure we're using the right name for getting the float value
            if (rfloat.test(name)) {
                name = styleFloat;
            }

            name = name.replace(rdashAlpha, fcamelCase);

            return style[name];
        },

        /**
        * Write Style
        * @param {Object} elem
        * @param {String} name
        * @param {String} value
        */
        Set: function(elem, name, value) {
            // don't set styles on text and comment nodes
            if (!elem || elem.nodeType == 3 || elem.nodeType == 8) {
                return;
            }

            // ignore negative width and height values #1599
            if ((name == "width" || name == "height") && parseFloat(value) < 0) {
                return;
            }

            var style = elem.style || elem;

            // IE uses filters for opacity
            if (!Browser.Features.opacity && name == "opacity") {
                if (value != undefined) {
                    // IE has trouble with opacity if it does not have layout
                    // Force it by setting the zoom level
                    style.zoom = 1;

                    // Set the alpha filter to set the opacity
                    var opacity = parseInt(value, 10) + "" == "NaN" ? "" : "alpha(opacity=" + value * 100 + ")";
                    var filter = style.filter || css(elem, "filter") || "";
                    style.filter = ralpha.test(filter) ? filter.replace(ralpha, opacity) : opacity;
                }
            }

            // Make sure we're using the right name for getting the float value
            if (rfloat.test(name)) {
                name = styleFloat;
            }

            name = name.replace(rdashAlpha, fcamelCase);

            if (value != undefined) {
                style[name] = value;
            }

            return;
        },

        /**
        * if the value is undefined, return the style value about specified style name from the specified element, <br/>
        * else set the style value for the specified style name of the specified element, or the second parameter <br/>
        * may be a kv pair without third parameter, like { "color": "green", "background": "gray", "width":"500" }.
        * @param {Object} elem
        * @param {String} name
        * @param {String} value
        */

        /**
        * multifunctional method to get and set values to a collection
        * @param {Object} elems
        * @param {String} key
        * @param {String} value
        * @param {Boolean} exec
        * @param {Function} fn
        * @param {Function} pass
        */
        access: function(elems, key, value, exec, fn, pass) {
            var length = 1; //elems.length;

            // Setting many attributes
            if (typeof key === "object") {
                for (var k in key) {
                    if (Sys.isFunction(k)) {
                        continue;
                    }
                    this.access(elems, k, key[k], exec, fn, value);
                }
                return elems;
            }

            // Setting one attribute
            if (value != undefined) {
                // Optionally, function values get executed if exec is true
                exec = !pass && exec;
                fn(elems, key, value, this);

                return elems;
            }

            // Getting an attribute
            return length ? fn(elems, key, null, this) : undefined;
        }
    };
})();

///////

(function() {
    var rclass = /[\n\t]/g,
        rspace = /\s+/,
        rreturn = /\r/g,
        rspecialurl = /href|src|style/,
        rtype = /(button|input)/i,
        rfocusable = /(button|input|object|select|textarea)/i,
        rclickable = /^(a|area)$/i,
        rradiocheck = /radio|checkbox/;

    Dom = {
        /**
        *
        *
        */
        setAttribute: function(elem, attr, value) {
            elem.setAttribute(attr, value);
        },

        /**
        * add classes for the specified documnet object, the classes can be example :"class1 calss2 class3"
        * @param {Object} elem
        * @param {String} value
        */
        addClass: function(elem, value) {
            if (value && typeof value == "string") {
                var classNames = (value || "").split(rspace);

                if (elem.nodeType == 1) {
                    if (!elem.className) {
                        elem.className = value;
                    }
                    else {
                        var className = " " + elem.className + " ", setClass = elem.className;
                        for (var c = 0, cl = classNames.length; c < cl; c++) {
                            if (className.indexOf(" " + classNames[c] + " ") < 0) {
                                setClass += " " + classNames[c];
                            }
                        }
                        elem.className = setClass.Trim();
                    }
                }
            }
            else {
                Sys.error("the value must be type string and not null!");
            }

            return elem;
        },

        /**
        * remove the specified class name from the specified element
        * @param {Object} elem
        * @param {String} value
        */
        removeClass: function(elem, value) {
            if ((value && typeof value == "string") || value == undefined) {
                var classNames = (value || "").split(rspace);

                if (elem.nodeType == 1 && elem.className) {
                    if (value) {
                        var className = (" " + elem.className + " ").replace(rclass, " ");
                        for (var c = 0, cl = classNames.length; c < cl; c++) {
                            className = className.replace(" " + classNames[c] + " ", " ");
                        }
                        elem.className = className.Trim();
                    } else {
                        elem.className = "";
                    }
                }
            } else {
                Sys.error("the value must be type string and not null!");
            }

            return elem;
        },

        /**
        * if the element has the specifed class, remove the class, else add the class.<br/>
        * if the _switch is true then do add, else if the _swithc is false then do remove.
        * @param {Object} elem
        * @param {String} value
        * @param {Boolean} _switch
        */
        toggleClass: function(elem, value, _switch) {
            var type = typeof value, isBool = typeof _switch === "boolean";
            var className, i = 0, state = _switch, classNames = value.split(rspace);

            if (_switch == undefined) {
                while ((className = classNames[i++])) {
                    // check each className given, space seperated list
                    state = isBool ? state : !this.hasClass(elem, className);
                    this[state ? "addClass" : "removeClass"](elem, className);
                }
            }
            else
                if (_switch == true) {
                this.addClass(elem, value);
            } else {
                this.removeClass(elem, value);
            }
        },

        /**
        * 
        * @param {Object} elem
        * @param {String} class_name
        */
        hasClass: function(elem, class_name) {
            var className = " " + class_name + " ";
            return (" " + elem.className + " ").replace(rclass, " ").indexOf(class_name) > -1;
        },

        /**
        * append a node to the specified element, it will be the last child.
        * @param {Object} elem
        * @param {Object} content
        */
        append: function(elem, content) {
            if (elem.nodeType == 1) {
                elem.appendChild(content);
            }
            return elem;
        },

        /**
        * append a node to the specified element, it will be the first child.
        * @param {Object} elem
        * @param {Object} content
        */
        prepend: function(elem, content) {
            if (elem.nodeType == 1) {
                elem.insertBefore(content, elem.firstChild);
            }
            return elem;
        },

        /**
        * add a node to the documnet, it will after the specified element.
        * @param {Object} elem
        * @param {Object} content
        */
        after: function(elem, content) {
            var pNode = elem.parentNode;
            if (pNode) {
                pNode.insertBefore(content, elem.nextSibling);
            } else {
                // do nothing
            }
        },

        /**
        * add a node to the documnet, it will before the specified element.
        * @param {Object} elem
        * @param {Object} content
        */
        before: function(elem, content) {
            var pNode = elem.parentNode;
            if (pNode) {
                pNode.insertBefore(content, elem);
            } else {
                // do nothing
            }
        },

        /**
        * add a node to the document, it will wrap the specified element.
        * @param {Object} r_elem
        * @param {Object} c_elem
        */
        wrap: function(r_elem, c_elem) {
            var pp = r_elem.parentNode;
            var next = r_elem.nextSibling;
            pp.removeChild(r_elem);
            c_elem.appendChild(r_elem);
            if (next) {
                pp.insertBefore(c_elem, next);
            } else {
                pp.appendChild(c_elem);
            }
        },

        // animate

        /**
        * 
        * @param {Object} elem
        * @param {Object} params
        * @param {Number} t(ms)
        * @param {Function} fn
        */
        animate: function(elem, params, t, fn) {

        },

        nodeName: function(elem, name) {
            return elem.nodeName && elem.nodeName.toUpperCase() === name.toUpperCase();
        },

        SetText: function(elem, text) {
            if (Browser.Type.gecko) {
                elem.textContent = text;
            }
            else {
                elem.innerText = text;
            }
        },

        SetValue: function(elem, text) {
            if (elem) {
                elem.value = text;
            }
        },

        GetDocumentSize: function() {
            var doc = doc || document;
            var el = (doc.compatMode != "CSS1Compat") ? doc.body : doc.documentElement;
            return { Y: Math.max(el.scrollHeight, el.clientHeight), X: Math.max(el.scrollWidth, el.clientWidth) };
        }
    };
})();

gleo.sys.AJAXRequest = function() {
    this.HttpRequseObj = null;

    this.URL = null;
    this.CallBack = null;
    this.Async = true;
    this.Content = null;

    //Set excute option for response info.
    this.Option = null;
    //    this.IEVersion = null;

    this.CreateHttpRequestObj();
};

gleo.sys.AJAXRequest.prototype.contentTypes = {
    form: "application/x-www-form-urlencoded",
    json: "application/json; charset=utf-8"
};

gleo.sys.AJAXRequest.prototype.accepts = {
    xml: "application/xml, text/xml",
    html: "text/html",
    script: "text/javascript, application/javascript",
    json: "application/json, text/javascript",
    text: "text/plain",
    _default: "*/*"
};

gleo.sys.AJAXRequest.prototype.CreateHttpRequestObj = function() {
    try {
        this.HttpRequseObj = new XMLHttpRequest();
    }
    catch (e) {
        if (!window.IEVersion) {
            this.CheckIEBrowserVer();
        }
        try {
            this.HttpRequseObj = new ActiveXObject(window.IEVersion);
        }
        catch (e) {
            // do nothing
        }
    }

    if (this.HttpRequseObj == null) {
        Sys.error("Your browser does not suppert AJAX.");
        return;
    }

    var ObjSelf = this;

    // 状态改变的事件触发器

    this.HttpRequseObj.onreadystatechange = function() {
        if (ObjSelf.HttpRequseObj.readyState == 4) {
            switch (ObjSelf.HttpRequseObj.status) {
                case 0:
                case 200:
                    ObjSelf.ExcuteCallBack(ObjSelf.HttpRequseObj);
                    break;

                case 401:
                    Sys.error("Access denied in Http Request");
                    break;

                case 500:
                    ObjSelf.ErrorCallBack(ObjSelf.HttpRequseObj);
                    break;

                default:
                    ObjSelf.ErrorCallBack(ObjSelf.HttpRequseObj);
                    break;
            }
        }
        else {
            ObjSelf.WaitLoading(ObjSelf.HttpRequseObj.readyState);
        }
    };
};

// 
gleo.sys.AJAXRequest.prototype.CheckIEBrowserVer = function() {
    if (window.ActiveXObject) {
        var BrowserVersions = ["MSXML2.XMLHTTP.5.0", "MSXML2.XMLHTTP.4.0", "MSXML2.XMLHTTP.3.0", "Microsoft.XMLHTTP", "MSXML2.XMLHTTP"];
        for (var i = 0; i < BrowserVersions.length; i++) {
            try {
                new ActiveXObject(BrowserVersions[i]);
                //                this.IEVersion = BrowserVersions[i];
                window.IEVersion = BrowserVersions[i];
                break;
            }
            catch (e) {
                this.HttpRequseObj = null;
                Debugger.Write("Your Browser Not Support AJAX.", e);
            }
        }
    }
};

gleo.sys.AJAXRequest.prototype.RandomlizeUrl = function(url) {
    var new_url = url;
    if (new_url.indexOf("?") > 0) {
        new_url += "&xxx=" + Math.random();
    } else {
        new_url += "?xxx=" + Math.random();
    }

    return new_url;
};

gleo.sys.AJAXRequest.prototype.Get = function() {
    if (!this.URL) {
        return;
    }

    var url = this.RandomlizeUrl(this.URL);

    this.HttpRequseObj.open("Get", url, this.Async);
    //    this.HttpRequseObj.setRequestHeader("Content-Type", "application/json; charset=utf-8");
    this.HttpRequseObj.setRequestHeader("Content-Type", this.contentTypes["form"]);
    this.HttpRequseObj.setRequestHeader("Content-Length", 0);
    this.HttpRequseObj.send(null);
};

gleo.sys.AJAXRequest.prototype.Post = function(dataType, contentType) {
    var Result = false;
    if (this.URL) {
        try {
            var url = this.RandomlizeUrl(this.URL);
            var ctype = contentType;
            if (!contentType) {
                ctype = "json";
            }
            this.HttpRequseObj.open("Post", url, this.Async);
            this.HttpRequseObj.setRequestHeader("Content-Type", this.contentTypes[ctype]);
            //            this.HttpRequseObj.setRequestHeader("Content-Type", "application/json; charset=utf-8");
            this.HttpRequseObj.setRequestHeader("Content-Length", this.Content ? this.Content.length : 0);
            if (dataType) {
                this.HttpRequseObj.setRequestHeader("Accept", this.accepts[dataType]);
            }
            this.HttpRequseObj.send(this.Content);
            Result = true;
        } catch (e) {
            Debugger.Write("Post URL: " + url, e);
        }
    }

    return Result;
};

gleo.sys.AJAXRequest.prototype.WaitLoading = function(RequestStatus) {
    return;
};

gleo.sys.AJAXRequest.prototype.ExcuteCallBack = function(HttpResponseObj) {
    if (this.CallBack != null) {
        this.CallBack.Excute(HttpResponseObj, this.Option);
    }
    else {
        Debugger.Write("Warning: From HttpRequest ExcuteCallBack. Here should have an callback method.");
    }
};

gleo.sys.AJAXRequest.prototype.ErrorCallBack = function(HttpResponseObj) {
    if (this.CallBack != null && this.CallBack.Error) {
        this.CallBack.Error(HttpResponseObj.responseText, this.Option);
    }
    else {
        ShowSystemException(HttpResponseObj.responseText, true);
    }
};

function ShowSystemException(SysExceptStr, IsShow) {
    if (IsShow) {
        var ExceptionWindow = window.open("", "_blank", "");

        if (ExceptionWindow == null) {
            alert(SysExceptStr);
        }
        else {
            ExceptionWindow.document.write(SysExceptStr);
        }
    }
    else {
        alert("System error.");
    }
}

GetErrorFrame = function(title, content) {
    alert("Error page: from gleo.sys.AJAXRequest.js");
    var ErrorFrame = [];
    ErrorFrame[ErrorFrame.length] = "<html>";
    ErrorFrame[ErrorFrame.length] = "<head>";
    ErrorFrame[ErrorFrame.length] = "<title>" + title + "</title>";
    ErrorFrame[ErrorFrame.length] = "<style>";
    ErrorFrame[ErrorFrame.length] = "body {font-family:\"Verdana\";font-weight:normal;font-size: .7em;color:black;} ";
    ErrorFrame[ErrorFrame.length] = "p {font-family:\"Verdana\";font-weight:normal;color:black;margin-top: -5px}";
    ErrorFrame[ErrorFrame.length] = "b {font-family:\"Verdana\";font-weight:bold;color:black;margin-top: -5px}";
    ErrorFrame[ErrorFrame.length] = "H1 { font-family:\"Verdana\";font-weight:normal;font-size:18pt;color:red }";
    ErrorFrame[ErrorFrame.length] = "H2 { font-family:\"Verdana\";font-weight:normal;font-size:14pt;color:maroon }";
    ErrorFrame[ErrorFrame.length] = "pre {font-family:\"Lucida Console\";font-size: .9em}";
    ErrorFrame[ErrorFrame.length] = ".marker {font-weight: bold; color: black;text-decoration: none;}";
    ErrorFrame[ErrorFrame.length] = ".version {color: gray;}";
    ErrorFrame[ErrorFrame.length] = ".error {margin-bottom: 10px;}";
    ErrorFrame[ErrorFrame.length] = ".expandable { text-decoration:underline; font-weight:bold; color:navy; cursor:hand; }";
    ErrorFrame[ErrorFrame.length] = "</style>";
    ErrorFrame[ErrorFrame.length] = "</head>";
    ErrorFrame[ErrorFrame.length] = '<body bgcolor="white">';
    ErrorFrame[ErrorFrame.length] = '<h2> <i>' + title + '</i> </h2></span>';
    ErrorFrame[ErrorFrame.length] = '<font face="Arial, Helvetica, Geneva, SunSans-Regular, sans-serif ">';
    ErrorFrame[ErrorFrame.length] = '<b> Description: </b>' + title;
    ErrorFrame[ErrorFrame.length] = '<table width=100% bgcolor=\"#ffffcc\"><tr><td><code><pre>';
    ErrorFrame[ErrorFrame.length] = '' + content;
    ErrorFrame[ErrorFrame.length] = '</pre></code></td></tr></table>';
    ErrorFrame[ErrorFrame.length] = '</body>';
    ErrorFrame[ErrorFrame.length] = '</html>';

    return ErrorFrame.join("");
};

///////
// JSON
//
if (!this.JSON) {
    this.JSON = {};
}

(function() {
    function f(n) {
        // Format integers to have at least two digits.
        return n < 10 ? '0' + n : n;
    }

    Date.prototype.toJSON = function(key) {

        return isFinite(this.valueOf()) ?
                this.getUTCFullYear() + '-' +
                f(this.getUTCMonth() + 1) + '-' +
                f(this.getUTCDate()) + 'T' +
                f(this.getUTCHours()) + ':' +
                f(this.getUTCMinutes()) + ':' +
                f(this.getUTCSeconds()) + 'Z' : null;
    };

    String.prototype.toJSON = function(key) {
        return this.valueOf();
    };

    Number.prototype.toJSON = function(key) {
        return this.valueOf();
    };

    Boolean.prototype.toJSON = function(key) {
        return this.valueOf();
    };

    var cx = /[\u0000\u00ad\u0600-\u0604\u070f\u17b4\u17b5\u200c-\u200f\u2028-\u202f\u2060-\u206f\ufeff\ufff0-\uffff]/g,
        escapable = /[\\\"\x00-\x1f\x7f-\x9f\u00ad\u0600-\u0604\u070f\u17b4\u17b5\u200c-\u200f\u2028-\u202f\u2060-\u206f\ufeff\ufff0-\uffff]/g,
        gap,
        indent,
        meta = {    // table of character substitutions
            '\b': '\\b',
            '\t': '\\t',
            '\n': '\\n',
            '\f': '\\f',
            '\r': '\\r',
            '"': '\\"',
            '\\': '\\\\'
        },
        rep,


    quote = function(string) {
        // If the string contains no control characters, no quote characters, and no backslash characters, then we can safely slap some quotes around it.
        // Otherwise we must also replace the offending characters with safe escape sequences.

        escapable.lastIndex = 0;
        return escapable.test(string) ?
            '"' + string.replace(escapable, function(a) {
                var c = meta[a];
                return typeof c === 'string' ? c :
                    '\\u' + ('0000' + a.charCodeAt(0).toString(16)).slice(-4);
            }) + '"' :
            '"' + string + '"';
    },

    str = function(key, holder) {
        // Produce a string from holder[key].

        var i,          // The loop counter.
            k,          // The member key.
            v,          // The member value.
            length,
            mind = gap,
            partial,
            value = holder[key];

        // If the value has a toJSON method, call it to obtain a replacement value.

        if (value && typeof value === 'object' &&
                typeof value.toJSON === 'function') {
            value = value.toJSON(key);
        }

        // If we were called with a replacer function, then call the replacer to obtain a replacement value.

        if (typeof rep === 'function') {
            value = rep.call(holder, key, value);
        }

        // What happens next depends on the value's type.

        switch (typeof value) {
            case 'string':
                return quote(value);

            case 'number':

                // JSON numbers must be finite. Encode non-finite numbers as null.

                return isFinite(value) ? String(value) : 'null';

            case 'boolean':
            case 'null':

                // If the value is a boolean or null, convert it to a string. Note:
                // typeof null does not produce 'null'. The case is included here in the remote chance that this gets fixed someday.

                return String(value);

                // If the type is 'object', we might be dealing with an object or an array or null.

            case 'object':

                // Due to a specification blunder in ECMAScript, typeof null is 'object', so watch out for that case.

                if (!value) {
                    return 'null';
                }

                // Make an array to hold the partial results of stringifying this object value.

                gap += indent;
                partial = [];

                // Is the value an array?

                if (Object.prototype.toString.apply(value) === '[object Array]') {

                    // The value is an array. Stringify every element. Use null as a placeholder for non-JSON values.

                    length = value.length;
                    for (i = 0; i < length; i += 1) {
                        partial[i] = str(i, value) || 'null';
                    }

                    // Join all of the elements together, separated with commas, and wrap them in brackets.

                    v = partial.length === 0 ? '[]' :
                    gap ? '[\n' + gap +
                            partial.join(',\n' + gap) + '\n' +
                                mind + ']' :
                          '[' + partial.join(',') + ']';
                    gap = mind;
                    return v;
                }

                // If the replacer is an array, use it to select the members to be stringified.

                if (rep && typeof rep === 'object') {
                    length = rep.length;
                    for (i = 0; i < length; i += 1) {
                        k = rep[i];
                        if (typeof k === 'string') {
                            v = str(k, value);
                            if (v) {
                                partial.push(quote(k) + (gap ? ': ' : ':') + v);
                            }
                        }
                    }
                } else {

                    // Otherwise, iterate through all of the keys in the object.

                    for (k in value) {
                        if (Object.hasOwnProperty.call(value, k)) {
                            v = str(k, value);
                            if (v) {
                                partial.push(quote(k) + (gap ? ': ' : ':') + v);
                            }
                        }
                    }
                }

                // Join all of the member texts together, separated with commas, and wrap them in braces.

                v = partial.length === 0 ? '{}' :
                gap ? '{\n' + gap + partial.join(',\n' + gap) + '\n' +
                        mind + '}' : '{' + partial.join(',') + '}';
                gap = mind;
                return v;
        }
    };

    JSON = {
        stringify: function(value, replacer, space) {

            // The stringify method takes a value and an optional replacer, and an optional space parameter, and returns a JSON text. The replacer can be a function that can replace values, or an array of strings that will select the keys.
            // A default replacer method can be provided. Use of the space parameter can produce text that is more easily readable.

            var i;
            gap = '';
            indent = '';

            // If the space parameter is a number, make an indent string containing that many spaces.

            if (typeof space === 'number') {
                for (i = 0; i < space; i += 1) {
                    indent += ' ';
                }

                // If the space parameter is a string, it will be used as the indent string.

            } else if (typeof space === 'string') {
                indent = space;
            }

            // If there is a replacer, it must be a function or an array.
            // Otherwise, throw an error.

            rep = replacer;
            if (replacer && typeof replacer !== 'function' &&
                    (typeof replacer !== 'object' ||
                     typeof replacer.length !== 'number')) {
                throw new Error('JSON.stringify');
            }

            // Make a fake root object containing our value under the key of ''.
            // Return the result of stringifying the value.

            return str('', { '': value });
        },

        parse: function(text, reviver) {

            // The parse method takes a text and an optional reviver function, and returns a JavaScript value if the text is a valid JSON text.

            var j;

            function walk(holder, key) {

                // The walk method is used to recursively walk the resulting structure so that modifications can be made.

                var k, v, value = holder[key];
                if (value && typeof value === 'object') {
                    for (k in value) {
                        if (Object.hasOwnProperty.call(value, k)) {
                            v = walk(value, k);
                            if (v !== undefined) {
                                value[k] = v;
                            } else {
                                delete value[k];
                            }
                        }
                    }
                }
                return reviver.call(holder, key, value);
            }

            // Parsing happens in four stages. In the first stage, we replace certain Unicode characters with escape sequences. JavaScript handles many characters incorrectly, either silently deleting them, or treating them as line endings.
            text = String(text);
            cx.lastIndex = 0;
            if (cx.test(text)) {
                text = text.replace(cx, function(a) {
                    return '\\u' +
                        ('0000' + a.charCodeAt(0).toString(16)).slice(-4);
                });
            }

            // In the second stage, we run the text against regular expressions that look for non-JSON patterns. We are especially concerned with '()' and 'new' because they can cause invocation, and '=' because it can cause mutation.
            // But just to be safe, we want to reject all unexpected forms.

            // We split the second stage into 4 regexp operations in order to work around crippling inefficiencies in IE's and Safari's regexp engines. First we replace the JSON backslash pairs with '@' (a non-JSON character). Second, we replace all simple value tokens with ']' characters. Third, we delete all open brackets that follow a colon or comma or that begin the text. Finally, we look to see that the remaining characters are only whitespace or ']' or ',' or ':' or '{' or '}'. If that is so, then the text is safe for eval.

            if (/^[\],:{}\s]*$/.test(text.replace(/\\(?:["\\\/bfnrt]|u[0-9a-fA-F]{4})/g, '@').replace(/"[^"\\\n\r]*"|true|false|null|-?\d+(?:\.\d*)?(?:[eE][+\-]?\d+)?/g, ']')
.replace(/(?:^|:|,)(?:\s*\[)+/g, ''))) {

                // In the third stage we use the eval function to compile the text into a JavaScript structure. The '{' operator is subject to a syntactic ambiguity
                // in JavaScript: it can begin a block or an object literal. We wrap the text in parens to eliminate the ambiguity.

                j = eval('(' + text + ')');

                // In the optional fourth stage, we recursively walk the new structure, passing each name/value pair to a reviver function for possible transformation.

                return typeof reviver === 'function' ?
                    walk({ '': j }, '') : j;
            }

            // If the text is not JSON parseable, then a SyntaxError is thrown.

            throw new SyntaxError('JSON.parse');
        }
    };
} ());