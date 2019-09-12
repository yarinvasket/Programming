using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RGB_ButtonsLabels_Transports_UserControls
{

    public partial class UserControl1 : UserControl
    {
        public Control[] arrControls;

        public UserControl1(int r, int c, string fullEmpty)
        {
            InitializeComponent();
            arrControls = new Control[r * c];
            this.Width = c * 31 + 7;
            this.Height = r * 31 + 7;
            if (fullEmpty == "Empty")
                return;

            Random myRand = new Random();
            Control temp = null;
            for (int j = 0; j < r; j++)
                for (int i = 0; i < c; i++)
                {
                    switch(myRand.Next(3))
                    {
                        case 0: temp = new Button(); break;
                        case 1: temp = new Label(); break;
                        case 2: temp = new TextBox(); break;
                    }
                    temp.Size = new Size(30, 30);
                    switch (myRand.Next(3))
                    {
                        case 0: temp.BackColor = Color.Red; break;
                        case 1: temp.BackColor = Color.Green; break;
                        case 2: temp.BackColor = Color.Blue; break;
                    }
                    temp.Location = new Point(3 + 31 * i, 3 + 31 * j);
                    this.arrControls[i + j * c] = temp;
                    this.Controls.Add(temp);
                }
        }
    }
}
