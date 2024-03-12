package myclass.gui;

import myclass.Figura;

import java.awt.*;

public class OknoRomb extends OknoFigura{

    Label labprzek1,labprzek2;
    TextField txtprzek1,txtprzek2;

    public OknoRomb(String title, Start parent) throws HeadlessException {
        super(title, parent);
        labprzek1 = new Label("Przekątna e");
        labprzek2 = new Label("Przekątna f");
        txtprzek1 = new TextField("wpisz rozmiar przekątnej e");
        txtprzek2 = new TextField("wpisz rozmiar przekątnej f");
        GridBagConstraints c = new GridBagConstraints();
        c.gridx=0;
        c.gridy=2;
        add(labprzek1,c);
        c.gridx=1;
        add(txtprzek1,c);
        c.gridx=0;
        c.gridy=3;
        add(labprzek2,c);
        c.gridx=1;
        add(txtprzek2,c);
    }

    @Override
    public Figura getFigura() {
        Double e = Double.parseDouble(txtprzek1.getText());
        Double f = Double.parseDouble(txtprzek2.getText());
        Figura tmp = new Figura(txtNazwa.getText(),"Romb", e*f/2);
        return tmp;
    }
}
