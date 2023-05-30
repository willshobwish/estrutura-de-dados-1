/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controller;

/**
 *
 * @author Willian
 */
public class Controller {

    private static final Controller controller = new Controller();

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
            System.out.print(e);
        }
        if (espaco) {
            System.out.print(" ");
        }
        if (quebraDeLinha) {
            System.out.println("");
        }
    }
}
