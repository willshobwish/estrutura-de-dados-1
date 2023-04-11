/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package model;

import java.util.NoSuchElementException;

/**
 *
 * @author Willian
 */
public class LinkedList<T> {

    private Node<T> head;
    private Node<T> tail;

    private static class Node<T> {

        T data;
        Node<T> prev;
        Node<T> next;

        public Node(T data) {
            this.data = data;
        }
    }

    public void addFirst(T element) {
        Node<T> newNode = new Node<>(element);
        if (head == null) {
            head = tail = newNode;
        } else {
            head.prev = newNode;
            newNode.next = head;
            head = newNode;
        }
    }

    public void addLast(T element) {
        Node<T> newNode = new Node<>(element);
        if (tail == null) {
            head = tail = newNode;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
        }
    }

    public void removeFirst() {
        if (head == null) {
            throw new NoSuchElementException();
        }
        head = head.next;
        if (head == null) {
            tail = null;
        } else {
            head.prev = null;
        }
    }

    public void removeLast() {
        if (tail == null) {
            throw new NoSuchElementException();
        }
        tail = tail.prev;
        if (tail == null) {
            head = null;
        } else {
            tail.next = null;
        }
    }

    public boolean isEmpty() {
        return head == null;
    }

    public void clear() {
        head = tail = null;
    }

    public void printList() {
        Node<T> current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

}
