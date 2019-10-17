package calculator2;

import javax.swing.*;
import java.awt.*;

public class MyJPanel extends JPanel {

    public MyJPanel(int witch, int height,LayoutManager manager) {
        setSize(witch, height);
        setLayout(manager);
    }
}
