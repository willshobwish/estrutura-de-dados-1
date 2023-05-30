/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controller;

import model.StringDinamica;

/**
 *
 * @author Willian
 */
public class Controller {

    private static final Controller controller = new Controller();
    private static StringDinamica stringDinamica = new StringDinamica();

    private Controller() {
    }

    /**
     * Padrão singleton
     *
     * @return
     */
    public static Controller getInstance() {
        return controller;
    }

    public void converterString(String entrada, boolean espaco, boolean quebraDeLinha) {
        char[] caracteres = entrada.toCharArray();
//        System.out.println("");
        for (char e : caracteres) {
            stringDinamica = stringDinamica.insert(stringDinamica, e);
        }
        if (espaco) {
            stringDinamica = stringDinamica.insert(stringDinamica, ' ');
        }
        if (quebraDeLinha) {
            stringDinamica = stringDinamica.insert(stringDinamica, '\n');
        }
    }

    public String imprime() {
        return stringDinamica.getString(stringDinamica);
    }
}
