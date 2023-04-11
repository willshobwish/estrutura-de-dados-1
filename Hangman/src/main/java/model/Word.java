/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package model;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Willian
 */
public class Word {

    private final String wordTextFilepath = "src\\main\\java\\assets\\Words.txt";
    private ArrayList<String> words = new ArrayList<>();

    public void getWordsText() {
        try {
            File ArquivoObjeto = new File(wordTextFilepath);
            Scanner Leitor = new Scanner(ArquivoObjeto);

            while (Leitor.hasNext()) {
                words.add(Leitor.next());
            }
            Leitor.close();
        } catch (FileNotFoundException e) {
            System.out.println("Ocorreu um erro no fechamento do arquivo");
            e.printStackTrace();
        }
        for (String eachWord : words) {
            System.out.println(eachWord);
        }
    }
}
