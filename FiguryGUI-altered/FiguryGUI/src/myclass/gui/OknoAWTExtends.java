package myclass.gui;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class OknoAWTExtends extends Frame {

    Button button;
    Label label;
    Checkbox checkbox1;
    Checkbox checkbox2;
    CheckboxGroup checkboxGroup;
    Choice choice;
    List list;
    Panel panel;

    public OknoAWTExtends(String title) throws HeadlessException {
        super(title);
        setSize(400,400);
        button = new Button("Dodaj");
        label = new Label("Opis");
        checkboxGroup = new CheckboxGroup();
        checkbox1 = new Checkbox("Opcja 1",false,checkboxGroup);
        checkbox2 = new Checkbox("Opcja 2",true,checkboxGroup);
        choice = new Choice();
        choice.add("element listy 1");
        choice.add("element listy 2");
        choice.add("element listy 3");
        panel = new Panel(new GridLayout(2,1));
        list = new List();
        list.setSize(new Dimension(200,200));
        //setLayout(new BorderLayout());
        setLayout(new GridBagLayout());
        GridBagConstraints c= new GridBagConstraints();
        c.gridx=0;
        c.gridy=0;
        add(panel,c);
        c.gridx=0;
        c.gridy=1;
        add(choice,c);
        panel.add(checkbox1);
        panel.add(checkbox2);
        c.gridx=0;
        c.gridy=2;
        add(label,c);
        c.gridx=0;
        c.gridy=4;
        add(button,c);
        c.gridx=0;
        c.gridy=5;
        add(list,c);

        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String wpis = "";
                if(checkbox1.getState()){
                    wpis+="wybrano opcje 1";
                }
                if(checkbox2.getState()){
                    wpis+="wybrano opcja 2";
                }

                wpis+= choice.getSelectedItem();
                list.add(wpis);
            }
        });
        setVisible(true);
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                dispose(); //to usuwa samo okno - jak cos jeszcze to nie zamknie tego
                //System.exit(0); //to zamyka aplikacje całą
            }
        });
    }
}
