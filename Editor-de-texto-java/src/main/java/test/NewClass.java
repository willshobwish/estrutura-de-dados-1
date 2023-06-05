package test;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
/**
 *
 * @author Willian Murayama
 */
public class NewClass {

    /**
     *
     * @param args
     */
    public static void main(String[] args) {
        StringDinamicaC a = new StringDinamicaC('a');
        a.inserir('b');
        a.inserir('c');

        a.printString();
        a.remover();
        a.printString();
    }
}
