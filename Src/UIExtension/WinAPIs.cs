using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace GLEO.UI
{
    public class WinAPIs
    {
        [DllImport("Kernel32.dll")]
        public static extern bool QueryPerformanceCounter(out long lpPerformanceCount);

        [DllImport("Kernel32.dll")]
        public static extern bool QueryPerformanceFrequency(out  long lpFrequency);

        [DllImport("user32", EntryPoint = "HideCaret")]
        public static extern bool HideCaret(IntPtr hWnd);

        [DllImport("user32.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr PostMessage(IntPtr hwnd, int wMsg, IntPtr wParam, IntPtr lParam);

        public const int WM_USER = 0x0400;

        public const int WM_KEYDOWN = 0x100;
        public const int WM_MOUSEACTIVATE = 0x0021;

        public const int WM_SELF_LOAD = WM_USER + 1;

        public const int VK_UP = 0x26;
        public const int VK_DOWN = 0x28;
        public const int VK_ESC = 0x1b;
        public const int VK_ENTER = 0x0d;

        public const int MA_NOACTIVATE = 0x0003;
    }
}
