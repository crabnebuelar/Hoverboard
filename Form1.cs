using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;

namespace Hoverboard_Control
{
    public partial class Form1 : Form
    {
        public Stopwatch watch { get; set; }
        int goStop = 0;
        int onOff = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            watch = Stopwatch.StartNew();
            port.Open();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.L)
            {
                writeToPort("Clock");
            }
            if (e.KeyCode == Keys.R)
            {
                writeToPort("Counter");
            }


            if (e.KeyCode == Keys.G)
            {
                if (goStop == 0)
                {
                    writeToPort("Go");
                    goStop = 1;
                }
                if (goStop == 1)
                {
                    writeToPort("Stopit");
                    goStop = 0;
                }
            }

            if (e.KeyCode == Keys.O)
            {
                if (onOff == 0)
                {
                    writeToPort("On");
                    onOff = 1;
                }
                if (onOff == 1)
                {
                    writeToPort("Off");
                    onOff = 0;
                }
            }
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            writeToPort("Stop");
        }
        
        public void writeToPort(String command)
        {
            if(watch.ElapsedMilliseconds > 15 || command.Equals("Stop"))
            {
                watch = Stopwatch.StartNew();

                port.Write(command);
            }
        }
    }
}
