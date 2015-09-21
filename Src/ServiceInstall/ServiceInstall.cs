using System;
using System.ComponentModel;
using System.Runtime.InteropServices;

namespace GLEO.OA.System
{

    public class ServiceInstall
    {
        #region Private Variables
        #endregion Private Variables

        #region Constants declaration.

        const int SC_MANAGER_CREATE_SERVICE = 0x0002;
        const int SERVICE_WIN32_OWN_PROCESS = 0x00000010;
        const int SERVICE_DEMAND_START = 0x00000003;
        const int SERVICE_ERROR_NORMAL = 0x00000001;
        const int STANDARD_RIGHTS_REQUIRED = 0xF0000;
        const int SERVICE_QUERY_CONFIG = 0x0001;
        const int SERVICE_CHANGE_CONFIG = 0x0002;
        const int SERVICE_QUERY_STATUS = 0x0004;
        const int SERVICE_ENUMERATE_DEPENDENTS = 0x0008;
        const int SERVICE_START = 0x0010;
        const int SERVICE_STOP = 0x0020;
        const int SERVICE_PAUSE_CONTINUE = 0x0040;
        const int SERVICE_INTERROGATE = 0x0080;
        const int SERVICE_USER_DEFINED_CONTROL = 0x0100;
        const int SERVICE_ALL_ACCESS = (STANDARD_RIGHTS_REQUIRED | SERVICE_QUERY_CONFIG | SERVICE_CHANGE_CONFIG | SERVICE_QUERY_STATUS | SERVICE_ENUMERATE_DEPENDENTS | SERVICE_START | SERVICE_STOP | SERVICE_PAUSE_CONTINUE | SERVICE_INTERROGATE | SERVICE_USER_DEFINED_CONTROL);
        const int SERVICE_AUTO_START = 0x00000002;

        #endregion Constants declaration.

        #region DLLImport

        [DllImport("advapi32.dll", SetLastError = true)]
        public static extern IntPtr OpenSCManager(string lpMachineName, string lpSCDB, int scParameter);

        [DllImport("Advapi32.dll", SetLastError = true)]
        public static extern IntPtr CreateService(IntPtr SC_HANDLE, string lpSvcName, string lpDisplayName, int dwDesiredAccess, int dwServiceType, int dwStartType, int dwErrorControl, string lpPathName, string lpLoadOrderGroup, int lpdwTagId, string lpDependencies, string lpServiceStartName, string lpPassword);

        [DllImport("advapi32.dll", SetLastError = true)]
        public static extern void CloseServiceHandle(IntPtr SCHANDLE);

        [DllImport("advapi32.dll", SetLastError = true)]
        public static extern int StartService(IntPtr SVHANDLE, int dwNumServiceArgs, string lpServiceArgVectors);

        [DllImport("advapi32.dll", SetLastError = true)]
        public static extern IntPtr OpenService(IntPtr SCHANDLE, string lpSvcName, int dwNumServiceArgs);

        [DllImport("advapi32.dll", SetLastError = true)]
        public static extern int DeleteService(IntPtr SVHANDLE);

        [DllImport("kernel32.dll", SetLastError = true)]
        public static extern int GetLastError();

        #endregion DLLImport

        /// <summary>
        /// 安装和运行
        /// </summary>
        /// <param name="svcPath">程序路径.</param>
        /// <param name="svcName">服务名</param>
        /// <param name="svcDispName">服务显示名称.</param>
        /// <returns>服务安装是否成功.</returns>
        public bool InstallService(string svcPath, string svcName, string svcDispName)
        {
            bool Result = false;

            IntPtr sc_handle = OpenSCManager(null, null, SC_MANAGER_CREATE_SERVICE);
            if (sc_handle.ToInt32() != 0)
            {
                try
                {
                    IntPtr sv_handle = CreateService(sc_handle, svcName, svcDispName, SERVICE_ALL_ACCESS, SERVICE_WIN32_OWN_PROCESS, SERVICE_AUTO_START, SERVICE_ERROR_NORMAL, svcPath, null, 0, null, null, null);

                    if (sv_handle.ToInt32() == 0)
                    {
                        throw new Win32Exception(Marshal.GetLastWin32Error());
                    }
                    else
                    {
                        int r = StartService(sv_handle, 0, null);
                        if (r == 0)
                        {
                            throw new Win32Exception(Marshal.GetLastWin32Error());
                        }

                        Result = true;
                    }
                }
                finally
                {
                    CloseServiceHandle(sc_handle);
                }
            }

            return Result;
        }
        /// <summary>
        /// 反安装服务.
        /// </summary>
        /// <param name="svcName">服务名.</param>
        public bool UnInstallService(string svcName)
        {
            const int GENERIC_WRITE = 0x40000000;
            const int DELETE = 0x10000;

            bool Result = false;

            IntPtr sc_handle = OpenSCManager(null, null, GENERIC_WRITE);
            if (sc_handle.ToInt32() != 0)
            {
                try
                {
                    IntPtr sv_handle = OpenService(sc_handle, svcName, DELETE);
                    if (sv_handle.ToInt32() != 0)
                    {
                        int i = DeleteService(sv_handle);
                        if (i != 0)
                        {
                            CloseServiceHandle(sc_handle);
                            Result = true;
                        }
                        else
                        {
                            throw new Win32Exception(Marshal.GetLastWin32Error());
                        }
                    }
                    else
                    {
                        throw new Win32Exception(Marshal.GetLastWin32Error());
                    }
                }
                finally
                {
                    CloseServiceHandle(sc_handle);
                }
            }
            else
            {
                throw new Win32Exception(Marshal.GetLastWin32Error());
            }

            return Result;
        }
    }
}