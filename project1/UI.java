package calculator2;

import java.awt.*;
import java.util.Arrays;

public class UI {
    private MyJbutton myJbutton0;
    private MyJbutton myJbutton1;
    private MyJbutton myJbutton2;
    private MyJbutton myJbutton3;
    private MyJbutton myJbutton4;
    private MyJbutton myJbutton5;
    private MyJbutton myJbutton6;
    private MyJbutton myJbutton7;
    private MyJbutton myJbutton8;
    private MyJbutton myJbutton9;
    private MyJbutton deleteLastIndex;
    private MyJbutton result;

    private MyJbutton addBtn;
    private MyJbutton substructBtn;
    private MyJbutton multiply;
    private MyJbutton divide;

    private MyJframe myJframe;
    private MyJLabel myJLabel;
    private MyTextField myTextField;

    private MyJPanel buttonPanell;
    private MyJPanel rightButtonPanell;
    private MyJPanel labelPanell;
    private StringBuilder builder;

    public UI() {
        builder = new StringBuilder();
        createLabel();
        createButton();
        createPannels();
        createListener();
        createFrame();


    }

    private void createLabel() {
        myJLabel = new MyJLabel();
        myTextField = new MyTextField(16);
    }

    private void createButton() {
        myJbutton0 = new MyJbutton("0");
        myJbutton1 = new MyJbutton("1");
        myJbutton2 = new MyJbutton("2");
        myJbutton3 = new MyJbutton("3");
        myJbutton4 = new MyJbutton("4");
        myJbutton5 = new MyJbutton("5");
        myJbutton6 = new MyJbutton("6");
        myJbutton7 = new MyJbutton("7");
        myJbutton8 = new MyJbutton("8");
        myJbutton9 = new MyJbutton("9");

        addBtn = new MyJbutton("+");
        substructBtn = new MyJbutton("-");
        multiply = new MyJbutton("*");
        divide = new MyJbutton("/");
        deleteLastIndex = new MyJbutton("C");
        result = new MyJbutton("=");

    }

    private void createPannels() {
        buttonPanell = new MyJPanel(100, 100, new GridLayout(4, 2));
        rightButtonPanell = new MyJPanel(100, 100, new GridLayout(4, 1));
        labelPanell = new MyJPanel(100, 100, new FlowLayout());
        labelPanell.setSize(100, 100);

        buttonPanell.add(myJbutton0);
        buttonPanell.add(myJbutton1);
        buttonPanell.add(myJbutton1);
        buttonPanell.add(myJbutton3);
        buttonPanell.add(myJbutton4);
        buttonPanell.add(myJbutton5);
        buttonPanell.add(myJbutton6);
        buttonPanell.add(myJbutton7);
        buttonPanell.add(myJbutton8);
        buttonPanell.add(myJbutton9);
        buttonPanell.add(deleteLastIndex);
        buttonPanell.add(deleteLastIndex);
        buttonPanell.add(result);

        rightButtonPanell.add(addBtn);
        rightButtonPanell.add(substructBtn);
        rightButtonPanell.add(multiply);
        rightButtonPanell.add(divide);
        //labelPanell.add(myJLabel);
        labelPanell.add(myTextField);
    }

    private void createFrame() {
        myJframe = new MyJframe(new BorderLayout(2, 2));
        myJframe.setMaximumSize(new Dimension(270, 300));
        myJframe.getContentPane().add(labelPanell, BorderLayout.NORTH);
        myJframe.getContentPane().add(buttonPanell, BorderLayout.CENTER);
        myJframe.getContentPane().add(rightButtonPanell, BorderLayout.EAST);

    }

    private void createListener() {

        myJbutton0.addActionListener(e -> {
            builder.append("0");

            myTextField.setText(builder.toString());

        });
        myJbutton1.addActionListener(e -> {
            builder.append("1");

            myTextField.setText(builder.toString());
        });
        myJbutton2.addActionListener(e -> {
            builder.append("2");

            myTextField.setText(builder.toString());
        });
        myJbutton3.addActionListener(e -> {
            builder.append("3");

            myTextField.setText(builder.toString());
        });
        myJbutton4.addActionListener(e -> {
            builder.append("4");

            myTextField.setText(builder.toString());
        });
        myJbutton5.addActionListener(e -> {
            builder.append("5");

            myTextField.setText(builder.toString());
        });
        myJbutton6.addActionListener(e -> {
            builder.append("6");

            myTextField.setText(builder.toString());
        });
        myJbutton7.addActionListener(e -> {
            builder.append("7");

            myTextField.setText(builder.toString());
        });
        myJbutton8.addActionListener(e -> {
            builder.append("8");

            myTextField.setText(builder.toString());
        });
        myJbutton9.addActionListener(e -> {
            builder.append("9");

            myTextField.setText(builder.toString());
        });
        addBtn.addActionListener(e -> {
            char b = builder.charAt(builder.length()-1);
            if (b != ' '){
                builder.append(" ");
                builder.append("+");
                builder.append(" ");
                myTextField.setText(builder.toString());
            }

        });
        divide.addActionListener(e -> {
            char b = builder.charAt(builder.length()-1);
            if (b != ' '){
                builder.append(" ");
                builder.append("/");
                builder.append(" ");
                myTextField.setText(builder.toString());
            }

        });
        multiply.addActionListener(e -> {
            char b = builder.charAt(builder.length()-1);
            if (b != ' '){
                builder.append(" ");
                builder.append("*");
                builder.append(" ");
                myTextField.setText(builder.toString());
            }

        });
        substructBtn.addActionListener(e -> {
            char b = builder.charAt(builder.length()-1);
            if (b != ' '){
                builder.append(" ");
                builder.append("-");
                builder.append(" ");
                myTextField.setText(builder.toString());
            }

        });
        deleteLastIndex.addActionListener(e -> {
            if (builder.length() != 0) {
                builder.deleteCharAt(builder.length() - 1);
                myTextField.setText(builder.toString());
            }

        });
        result.addActionListener(e -> {
            char b = builder.charAt(builder.length()-1);
            if (b !=' '){
            }
            createCalculate();
            myTextField.setText(builder.toString());
            builder.delete(0, builder.length());
        });

    }

    private void createCalculate() {
        String[] array = builder.toString().split(" ");
        System.out.println(Arrays.toString(array));
        double result =0;
        for (int i =0; i<array.length; i++){
            if (i==0){
                result = Double.parseDouble(array[i]);
            }
            if (array[i].equals("+")){
              result+=  Double.parseDouble(array[i+1]);
            }
            if (array[i].equals("-")){
                result-=  Double.parseDouble(array[i+1]);
            }
            if (array[i].equals("/")){
                result/=  Double.parseDouble(array[i+1]);
            }
            if (array[i].equals("*")){
                result*=  Double.parseDouble(array[i+1]);
            }
        }
        builder.delete(0, builder.length());
        builder.append("" + result);
        System.out.println(result);


    }

}

