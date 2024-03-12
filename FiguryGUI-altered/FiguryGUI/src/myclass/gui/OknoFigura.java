package myclass.gui;

import myclass.Figura;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class OknoFigura extends Frame {

    Label labNazwa;
    TextField txtNazwa;
    Button btnZapisz;

    Start parent;

    public OknoFigura(String title, Start parent) throws HeadlessException {
        super(title);
        this.parent = parent;
        labNazwa = new Label("Nazwa");
        txtNazwa = new TextField("Wpisz nazwę figury");
        btnZapisz = new Button("Zapisz");
        setSize(400,200);
        setVisible(true);

        setLayout(new GridBagLayout());
        GridBagConstraints c = new GridBagConstraints();
        c.gridx = 0;
        c.gridy = 0;
        c.fill= GridBagConstraints.HORIZONTAL;
        add(labNazwa,c);
        c.gridx = 1;
        add(txtNazwa,c);

        c.gridx=0;
        c.gridy=5;
        c.gridwidth=2;
        add(btnZapisz,c);

        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                parent.closeOknoFigura();
            }
        });

        btnZapisz.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                parent.closeOknoFiguraSave();
            }
        });
    }

    public Figura getFigura() {
        return null;
    }
}
