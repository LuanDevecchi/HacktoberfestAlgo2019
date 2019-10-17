package calculator2;

import javax.swing.*;
import java.awt.*;

public class MyJframe extends JFrame {
    public MyJframe(LayoutManager manaset){
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setSize(270, 300);
        setLayout(manaset);
        setVisible(true);


    }

}
