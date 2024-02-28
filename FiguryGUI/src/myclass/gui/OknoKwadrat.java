package myclass.gui;

import myclass.Figura;

import java.awt.*;

public class OknoKwadrat extends OknoFigura{
    Label labBok;
    TextField txtBok;

    public OknoKwadrat(String title, Start parent) throws HeadlessException {
        super(title, parent);
        labBok = new Label("Bok");
        txtBok = new TextField("wpisz rozmiar boku");
        GridBagConstraints c = new GridBagConstraints();
        c.gridx=0;
        c.gridy=2;
        add(labBok,c);
        c.gridx=1;
        add(txtBok,c);
    }

    @Override
    public Figura getFigura() {
        Double bok = Double.parseDouble(txtBok.getText());
        Figura tmp = new Figura(txtNazwa.getText(),"Kwadrat", bok*bok);
        return tmp;
    }
}
