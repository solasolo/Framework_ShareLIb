using System.Drawing;
using System.Threading;

namespace GLEO.MES.UI
{
    public class FlashLabel : ThreadLabel
    {

        int _times;
        int _interval;

        public void Flash(int times, int interval)
        {
            this._times = times;
            this._interval = interval;

            Thread th = new Thread(ThreadMethod);
            th.IsBackground = true;
            th.Start();
        }

        private void ThreadMethod()
        {
            int t = 0;

            Color fc = this.ForeColor;
            Color bc = this.BackColor;

            Color _fc = this.ForeColor;
            Color _bc = this.BackColor;

            while (t < _times)
            {
                this.BackColor = fc;

                this.ForeColor = bc;

                fc = this.ForeColor;
                bc = this.BackColor;

                Thread.Sleep(_interval);
                t++;
            }

            this.BackColor = bc;

            this.ForeColor = fc;
        }
    }
}