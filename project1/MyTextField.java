package calculator2;

import javax.swing.*;
import java.awt.*;

public class MyTextField extends JTextField {
    public MyTextField(int columns) {
        super(columns);
        Font font = new Font("Courier", Font.ITALIC, 16);
        super.setFont(font);
        super.setForeground(Color.GRAY);
    }
}
