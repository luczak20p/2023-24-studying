package myclass.gui;

import myclass.Figura;

import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class OknoDane extends Frame {
    Label nazwa,typ,pole;
    Label nazwa1,typ1, pole1;

    Start parent;

    public OknoDane(Figura tmp,Start parent) throws HeadlessException {
        super("DANE");
        this.nazwa1 = new Label(tmp.getNazwa());
        this.typ1 = new Label(tmp.getTyp());
        this.pole1 = new Label(tmp.getPole()+"");
        this.parent = parent;
        setSize(400,200);
        setVisible(true);

        nazwa = new Label("nazwa: ");
        typ = new Label("typ: ");
        pole = new Label("pole: ");

        setLayout(new GridBagLayout());
        GridBagConstraints c = new GridBagConstraints();

        c.gridx=0;
        c.gridy=1;
        add(nazwa,c);
        c.gridx=1;
        add(nazwa1,c);
        c.gridx=0;
        c.gridy=2;
        add(typ,c);
        c.gridx=1;
        add(typ1,c);
        c.gridx=0;
        c.gridy=3;
        add(pole,c);
        c.gridx=1;
        add(pole1,c);

        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                parent.closeOknoDane();
            }
        });

    }
}
