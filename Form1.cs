using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace MYgui
{
    public partial class Form1 : Form
    {
        bool isConnected = false;
        String[] _port;
        SerialPort myPort = new SerialPort("COM8", 9600, Parity.None, 8, StopBits.One);        

        public Form1()
        {
            InitializeComponent();
        }

        private bool arduinoConnection()
        {
            isConnected = true;
            return isConnected;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            if (isConnected == true)
            {
                int secondsF = Convert.ToInt32(textBox3.Text);
                char myChar = Convert.ToChar("F");
            }
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            if (isConnected == true)
            {
                int secondsB = Convert.ToInt32(textBox4.Text);
                char myChar = Convert.ToChar("B");
            }
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            if (isConnected == true)
            {
                int secondsL = Convert.ToInt32(textBox5.Text);
                char myChar = Convert.ToChar("L");
            }
        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {
            int secondsR = Convert.ToInt32(textBox6.Text);
            char myChar = Convert.ToChar("R");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int  secondsF = Convert.ToInt32(textBox3.Text);
            int secondsB = Convert.ToInt32(textBox4.Text); 
            int secondsL = Convert.ToInt32(textBox5.Text);
            int secondsR = Convert.ToInt32(textBox4.Text);

        }

    }
}
