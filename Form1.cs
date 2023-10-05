using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MyJson;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;


namespace WindowsFormsApp4
{
    public partial class Form1 : Form
    {
       static MyJson.NetJson netJS = new MyJson.NetJson();

        class ListObserver : MyJson.Observer
        {
            Form1 f;
            public ListObserver(Form1 _f)
            {
                f = _f;

            }
            public override void update()
            {
                f.show();
            }
        };

      //  String text;
        public Form1()
        {
            InitializeComponent();
        }
       
        //public void load()
        //{
        //    netJS.load(text);

        //}
       

        private void button4_Click(object sender, EventArgs e)
        {//add
            string key = textBox1.Text;
            string value = textBox2.Text;

            netJS.add_after(key, value);

            netJS.addObserver(new ListObserver(this));

        }

        private void button3_Click(object sender, EventArgs e)
        {//next
            netJS.next();
            // netJS.Update();
            netJS.addObserver(new ListObserver(this));
        }

        private void button2_Click(object sender, EventArgs e)
        {//back
            netJS.back();
            // netJS.Update();
            netJS.addObserver(new ListObserver(this));
        }

        private void button1_Click(object sender, EventArgs e)
        {//down
            netJS.down();
            // netJS.Update();
            netJS.addObserver(new ListObserver(this));
        }

       

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
       public void show()
        {
             String str = "Json: \n ";
            //   MyList.iterator itr = list.getItr();

            //str += new String((netJS.getcur()).c_str());
            //label1.Text = str + ", ";
            // netJS.
            //while (netJS.has_next())
            //{
            //    str+= netJS.next();
            //   label1.Text = str + ", ";
            //}
            str += netJS.getJsonString();
            label1.Text = str;
            //label1.Text = str;
            //{
            //    str += itr.next().ToString() + ", ";
            //    label1.Text = str;
            //}

            // netJS.show();
        }
        private void загрузитьJsonToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.Filter = "  All files (*.*) | *.*";
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                netJS.load(dialog.FileName);
               
               show();
               
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
           netJS.addObserver(new ListObserver(this));
            //  show();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button5_Click(object sender, EventArgs e)
        {//добавить в начало
            string key = textBox1.Text;
            string value = textBox2.Text;

            netJS.add_in_start(key,value);

            netJS.addObserver(new ListObserver(this));
        }

        private void button6_Click(object sender, EventArgs e)
        {//преобразование в список
            netJS.converting_to_list();
            netJS.addObserver(new ListObserver(this));
        }

        private void button7_Click(object sender, EventArgs e)
        {//delete
            netJS.del();
            netJS.addObserver(new ListObserver(this));
        }
    }
}
