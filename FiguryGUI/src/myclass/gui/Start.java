package myclass.gui;

import myclass.Figura;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.ArrayList;

public class Start extends Frame {
    Button btnDodaj;
    Button btnUsun;
    Button btnDane;
    Choice chFigura;
    MenuBar menu;
    Menu mPlik;
    MenuItem itmZapisz;
    MenuItem itmOdczyt;
    MenuItem itmKoniec;
    List ltFigury;
    Panel panelL;
    Panel panelR;

    ArrayList<Figura> bazaFigur;

    OknoFigura oknoFigura; //referencja na okno dialogowe wprowadzające dane
    public Start(String title, ArrayList<Figura> bazaFigur) throws HeadlessException {
        super(title);
        this.bazaFigur=bazaFigur;
        setSize(400,500);
        setVisible(true);
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                dispose();
            }
        });
        panelL = new Panel();
        panelL.setPreferredSize(new Dimension(200,400));
        panelR = new Panel();
        btnDodaj = new Button("Dodaj");
        btnUsun = new Button("Usuń");
        btnDane = new Button("Dane");
        ltFigury = new List();
        chFigura = new Choice();
        chFigura.add("Kwadrat");
        chFigura.add("Koło");
        chFigura.add("Prostokąt");
        menu = new MenuBar();
        mPlik = new Menu("Plik");
        itmZapisz = new MenuItem("Zapisz");
        itmOdczyt = new MenuItem("Oczytaj");
        itmKoniec = new MenuItem("Koniec");
        mPlik.add(itmZapisz);
        mPlik.add(itmOdczyt);
        mPlik.add(itmKoniec);
        menu.add(mPlik);
        panelL.setLayout(new BorderLayout());
        panelL.add(ltFigury, BorderLayout.CENTER);
        panelR.setLayout(new GridBagLayout());
        GridBagConstraints c =new GridBagConstraints();
        c.gridx=0;
        c.gridy=0;
        c.insets = new Insets(10,10,10,0);
        c.ipadx=100;
        c.anchor = GridBagConstraints.NORTHWEST;
        panelR.add(btnDodaj, c);
        c.gridy=1;
        panelR.add(btnDane, c);
        c.gridy=2;
        panelR.add(btnUsun, c);
        c.gridy=3;
        panelR.add(chFigura, c);
        setMenuBar(menu);
        setLayout(new BorderLayout());
        add(panelL,BorderLayout.WEST);
        add(panelR,BorderLayout.EAST);


        itmKoniec.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });

        btnDodaj.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                showAddFiguraWindow(chFigura.getSelectedItem());


            }
        });


    }

    private void showAddFiguraWindow(String selectedFigura) {
        setEnabled(false);
        switch (selectedFigura){
            case "Kwadrat": oknoFigura = new OknoKwadrat("KWADRAT",this);
            default: setEnabled(true);
        }
    }

    public void closeOknoFigura() {
        oknoFigura.dispose();
        setEnabled(true);
    }

    public void closeOknoFiguraSave() {
        Figura tmpFigura =  oknoFigura.getFigura();
        bazaFigur.add(tmpFigura);
        oknoFigura.dispose();
        ltFigury.add(tmpFigura.getTyp()+":"+tmpFigura.getNazwa());
        setEnabled(true);
    }
}
