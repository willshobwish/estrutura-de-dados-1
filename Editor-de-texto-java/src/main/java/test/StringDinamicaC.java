package test;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
/**
 *
 * @author Willian Murayama
 */
public class StringDinamicaC {

    private StringDinamicaC proximo;
    private StringDinamicaC anterior;
    private char elemento;

    /**
     *
     * @param elemento
     */
    public StringDinamicaC(char elemento) {
        anterior = null;
        proximo = null;
        this.elemento = elemento;
    }

    /**
     *
     */
    public void remover() {
        StringDinamicaC auxiliar = this;
        while (auxiliar.proximo != null) {
            auxiliar = auxiliar.proximo;
        }

        auxiliar.anterior.proximo = null;
    }

    /**
     *
     * @param data
     */
    public void inserir(char data) {
        StringDinamicaC novo = new StringDinamicaC(data);
        StringDinamicaC auxiliar = this;
        StringDinamicaC anterior = null;
        if (auxiliar.proximo == null) {
            auxiliar.proximo = novo;
        } else {
            while (auxiliar.proximo != null) {
                anterior = auxiliar;
                auxiliar = auxiliar.proximo;
            }
            novo.anterior = auxiliar;
            auxiliar.proximo = novo;
        }
    }

    /**
     *
     */
    public void printString() {
        StringDinamicaC auxiliar = this;

        // Traverse through the LinkedList
        while (auxiliar != null) {
            // Print the data at current node
            System.out.println(auxiliar.elemento);

            // Go to proximo node
            auxiliar = auxiliar.proximo;
        }
//        return dados;
    }
}
