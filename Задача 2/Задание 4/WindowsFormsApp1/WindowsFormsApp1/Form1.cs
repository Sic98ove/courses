using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Security.Cryptography;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        
        public int[] intArray;
        public Form1()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Создать одномерный массив длинной n заполненный случайными данными.
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public int[] CreateArray(int n)
        {
            var rand = new Random();
            int[] arr = new Int32[n];

            for (int i = 0; i < n; i++)
            {

                arr[i] = rand.Next(101);
            }

            return arr;
        }

        public void DisplayArray(int[] array)
        {
            for (int i = 0; i < array.Length; i++)
            {
                Console.WriteLine(array[i]);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            intArray = new int[Int32.Parse(textBox1.Text)];

            intArray = CreateArray(Int32.Parse(textBox1.Text));

            DisplayArray(intArray);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            byte[] tmpSource = new byte[intArray.Length];
            byte[] tmpHash;

            for (int i = 0; i < intArray.Length; i++)
            {
                tmpSource[i] = Convert.ToByte(intArray[i]);
            }
            tmpHash = new MD5CryptoServiceProvider().ComputeHash(tmpSource);
            Console.WriteLine(tmpSource.ToString());
            for (int i = 0; i < tmpHash.Length; i++)
            {
                Console.WriteLine(tmpHash[i]);
            }

            int tempValue = Int32.Parse(textBox2.Text);

            byte[] temp = new byte[1]; 
            temp[0] = Convert.ToByte(tempValue);

            byte[] valueHash = new MD5CryptoServiceProvider().ComputeHash(temp);

            bool flag = false;
            
            for (int i = 0; i < tmpHash.Length; i++)
            {
                if (tmpHash[i] == valueHash[0])
                {
                    flag = true;
                    break;
                    
                }
            }

            if (flag)
            {
                MessageBox.Show("Искомое значение есть в массиве");
            }
            else
            {
                MessageBox.Show("Искомого значения нет в массиве");
            }

        }
    }
}
