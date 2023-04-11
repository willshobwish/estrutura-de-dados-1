/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tests;

import model.LinkedList;

/**
 *
 * @author Willian Murayama
 */
public class Test {

    public static void main(String[] args) {
        LinkedList<Character> lista = new LinkedList<>();
        lista.adicionarFinal('a');
        lista.adicionarFinal('b');
        lista.adicionarFinal('e');
        lista.adicionarFinal('l');
        lista.adicionarFinal('h');
        lista.adicionarFinal('a');
        lista.imprimirLista();
    }

}
