/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package model;

import java.util.NoSuchElementException;

/**
 *
 * @author Willian
 * @param <TipoDeDado>
 */
public class LinkedList<TipoDeDado> {

    private No<TipoDeDado> comeco;
    private No<TipoDeDado> inicio;

    private static class No<TipoDeDado> {

        TipoDeDado dado;
        No<TipoDeDado> anterior;
        No<TipoDeDado> proximo;

        public No(TipoDeDado dado) {
            this.dado = dado;
        }
    }

    /**
     *
     * @param elemento
     */
    public void adicionarComeco(TipoDeDado elemento) {
        No<TipoDeDado> newNode = new No<>(elemento);
        if (comeco == null) {
            comeco = inicio = newNode;
        } else {
            comeco.anterior = newNode;
            newNode.proximo = comeco;
            comeco = newNode;
        }
    }

    /**
     *
     * @param elemento
     */
    public void adicionarFinal(TipoDeDado elemento) {
        No<TipoDeDado> newNode = new No<>(elemento);
        if (inicio == null) {
            comeco = inicio = newNode;
        } else {
            inicio.proximo = newNode;
            newNode.anterior = inicio;
            inicio = newNode;
        }
    }

    /**
     *
     */
    public void removerPrimeiro() {
        if (comeco == null) {
            throw new NoSuchElementException();
        }
        comeco = comeco.proximo;
        if (comeco == null) {
            inicio = null;
        } else {
            comeco.anterior = null;
        }
    }

    /**
     *
     */
    public void removerUltimo() {
        if (inicio == null) {
            throw new NoSuchElementException();
        }
        inicio = inicio.anterior;
        if (inicio == null) {
            comeco = null;
        } else {
            inicio.proximo = null;
        }
    }

    /**
     *
     * @return
     */
    public boolean vazio() {
        return comeco == null;
    }

    /**
     *
     */
    public void limpar() {
        comeco = inicio = null;
    }

    /**
     *
     */
    public void imprimirLista() {
        No<TipoDeDado> current = comeco;
        while (current != null) {
            System.out.print(current.dado + "");
            current = current.proximo;
        }
        System.out.println();
    }

}
