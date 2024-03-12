package myclass.gui;

import myclass.Figura;

import java.awt.*;

public class OknoKolo extends OknoFigura{

    Label labPromien;
    TextField txtPromien;

    public OknoKolo(String title, Start parent) throws HeadlessException {
        super(title, parent);
        labPromien = new Label("Promień");
        txtPromien = new TextField("wpisz promień");
        GridBagConstraints c = new GridBagConstraints();
        c.gridx=0;
        c.gridy=2;
        add(labPromien,c);
        c.gridx=1;
        add(txtPromien,c);
    }

    @Override
    public Figura getFigura() {
        Double r = Double.parseDouble(txtPromien.getText());
        Figura tmp = new Figura(txtNazwa.getText(),"Koło", r*r*Math.PI);
        return tmp;
    }
}
