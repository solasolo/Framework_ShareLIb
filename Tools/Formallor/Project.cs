using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;
using System.Xml;

namespace Formallor
{
    enum ProjectType
    {
        CPP,
        CSharp,
    }

    enum ProjectVersion
    {
    }

    class Build
    {
        private string OutputDirectory;
    }

    class PathList
    { 
    }

    class LibList
    { 
    }

    class Project
    {
        private Solution Owner;

        XmlDocument ProjectDoc;

        private ProjectType Type;
        private ProjectVersion Version;
        private string Directory;

        internal Project(XmlDocument doc)
        {
            this.ProjectDoc = doc;
        }

        internal  static Project Load(string path, string name, string ext)
        {
            Project Result = null;

            XmlDocument Doc = new XmlDocument();
            Doc.Load(path + "//" + name);

            if (ext.StartsWith("cs"))
            {
                Result = new CSProject(Doc);
            }
            else if (ext.StartsWith("vcx"))
            {
                Result = new CPPProject(Doc);
            }
            else if (ext.StartsWith("vc"))
            {
                Result = new CPPProject(Doc);
            }

            return Result;
        }
    }

    class CSProject : Project
    {
        internal CSProject(XmlDocument doc)
            : base(doc)
        { 
        }
    }

    class CPPProject : Project
    {
        internal CPPProject(XmlDocument doc)
            : base(doc)
        { 
        }
    }

    class Solution
    {
        private string Directory;
        private List<Project> Projects;

        private void LoadProjects()
        {
            DirectoryInfo di = new DirectoryInfo(this.Directory);
            this.Load(di);
        }

        private void Load(DirectoryInfo di)
        {
            DirectoryInfo[] SubDirs = di.GetDirectories();
            foreach (DirectoryInfo d in SubDirs)
            {
                FileInfo[] Files = d.GetFiles();
                foreach(FileInfo f in Files)
                {
                    string FileName = f.Name;
                    string FileExt = f.Extension.ToLower();

                    if (FileExt.EndsWith("proj"))
                    {
                        Project proj = Project.Load(f.DirectoryName, FileName, FileExt);

                        if (proj != null)
                        {
                            this.Projects.Add(proj);
                        }
                    }
                }

                this.Load(d);
            }        
        }

        public Solution(string path)
        {
            this.Directory = path;
            this.Projects = new List<Project>();

            this.LoadProjects();
        }
    }
}
