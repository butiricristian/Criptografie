using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Numerics;

namespace Lab2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            DateTime d1 = DateTime.Now;
            gcdEuclid(new BigInteger(1231241), new BigInteger(3));
            DateTime d2 = DateTime.Now;
            gcdDifference(new BigInteger(1231241), new BigInteger(3));
            DateTime d3 = DateTime.Now;

            chart1.Series["GCD"].Points.AddXY("Euclid", (d2 - d1).Milliseconds);
            chart1.Series["GCD"].Points.AddXY("Subtractions", (d3 - d2).Milliseconds);
        }

        public BigInteger gcdEuclid(BigInteger a, BigInteger b)
        {
            BigInteger remainder;
            while(b != 0)
            {
                remainder = a % b;
                a = b;
                b = remainder;
            }
            return a;
        }

        public BigInteger gcdDifference(BigInteger a, BigInteger b)
        {
            while(a > b)
            {
                a = a - b;
            }
            while(b > a)
            {
                b = b - a;
            }
            return a;
        }


    }
}
