package myclass.gui;

import myclass.Figura;

import java.io.*;
import java.util.ArrayList;
import java.util.Objects;

public class App {
    public static void main(String[] args) {
        //OknoAWTExtends okno = new OknoAWTExtends("testing awt");
        ArrayList <Figura> bazaFigur;//tutaj bedziemy przechowywac liste figur
        bazaFigur = new ArrayList<Figura>();
        //przyklad uzycia serializacji do zapisu listy figur
//        Figura tmp = new Figura("Magiczny","Kwadrat",45.00);
//        bazaFigur.add(tmp);
        //zapis arraylisty do pliku
//        try {
//            ObjectOutputStream ouS = new ObjectOutputStream(new FileOutputStream("test.bin"));
//            ouS.writeObject(bazaFigur);
//            ouS.close();
//        } catch (IOException e) {
//            throw new RuntimeException(e);
//        }
//
//        try {
//            ObjectInputStream inS = new ObjectInputStream(new FileInputStream("test.bin"));
//            ArrayList <Figura> bazaFigur2 = (ArrayList<Figura>) inS.readObject();
//            System.out.println(bazaFigur2.get(0).getNazwa());
//
//
//        } catch (IOException e) {
//            throw new RuntimeException(e);
//        } catch (ClassNotFoundException e) {
//            throw new RuntimeException(e);
//        }


        /// zrobić zapisywanie do pliku, czytanie z pliku i czytanie danych wybranego z listy elementu

        Start oknoStart = new Start("Figury", bazaFigur);
    }
}
