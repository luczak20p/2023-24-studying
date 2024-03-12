package myclass.gui;

import myclass.Figura;

import java.awt.*;

public class OknoProstokat extends OknoFigura{

    Label labBok1,labBok2;
    TextField txtBok1,txtBok2;

    public OknoProstokat(String title, Start parent) throws HeadlessException {
        super(title, parent);
        labBok1 = new Label("Bok a");
        labBok2 = new Label("Bok b");
        txtBok1 = new TextField("wpisz rozmiar boku a");
        txtBok2 = new TextField("wpisz rozmiar boku b");
        GridBagConstraints c = new GridBagConstraints();
        c.gridx=0;
        c.gridy=2;
        add(labBok1,c);
        c.gridx=1;
        add(txtBok1,c);
        c.gridx=0;
        c.gridy=3;
        add(labBok2,c);
        c.gridx=1;
        add(txtBok2,c);
    }

    @Override
    public Figura getFigura() {
        Double bok1 = Double.parseDouble(txtBok1.getText());
        Double bok2 = Double.parseDouble(txtBok2.getText());
        Figura tmp = new Figura(txtNazwa.getText(),"Prostokąt", bok1*bok2);
        return tmp;
    }
}
