package test;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Willian Murayama
 */
public class teste {

    private teste proximo;
    private teste anterior;
    private char elemento;

    public teste(char elemento) {
        anterior = null;
        proximo = null;
        this.elemento = elemento;
    }

    public void insert(char data) {
        // Create a new node with given data
        teste new_node = new teste(data);
        teste auxiliar = this;
        // If the Linked List is empty,
        // then make the new node as head
        if (proximo == null) {
            proximo = new_node;
        } else {
            // Else traverse till the last node
            // and insert the new_node there
//            node last = list.head;
            while (auxiliar.proximo != null) {
                auxiliar = auxiliar.proximo;
            }

            // Insert the new_node at last node
            auxiliar.proximo = new_node;
        }
    }

    public void getString() {
        teste currnode = this;

        // Traverse through the LinkedList
        while (currnode != null) {
            // Print the data at current node
            System.out.println(currnode.elemento);

            // Go to proximo node
            currnode = currnode.proximo;
        }
//        return dados;
    }
}
