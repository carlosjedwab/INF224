/**
 * @file MainWindow.java
 * @author Carlos Jedwab
 * @brief Class used to create the main window of the application
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.*;
import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JToolBar;
import javax.swing.JButton;
import java.io.*;
import java.net.*;

/**
 * @brief This class is used to create the main window of the application
 */
public class MainWindow extends JFrame {
  private static final long serialVersionUID = 1L;

  private JTextField writeArea; /* The text field where the user will write the request */
  private JTextArea readArea; /* The text area where the response will be displayed */
  private static Client client; /* The client object */

  /**
   * @brief Construct a new Main Window object
   */
  public MainWindow() {
    setDefaultCloseOperation(EXIT_ON_CLOSE);
    setLayout(new BorderLayout());

    readArea = new JTextArea(10, 20);
    JScrollPane scrollPane = new JScrollPane(readArea);
    add(scrollPane, BorderLayout.CENTER);

    writeArea = new JTextField(20);
    Action createAction = new ButtonAction(writeArea, readArea, client, "create");
    Action addAction = new ButtonAction(writeArea, readArea, client, "add");
    Action deleteAction = new ButtonAction(writeArea, readArea, client, "delete");
    Action playAction = new ButtonAction(writeArea, readArea, client, "play");
    Action displayAction = new ButtonAction(writeArea, readArea, client, "display");
    Action exitAction = new AbstractAction("Exit") {
      private static final long serialVersionUID = 1L;
      @Override
      public void actionPerformed(ActionEvent e) {
        System.exit(0);
      }
    };

    JMenuBar menuBar = new JMenuBar();
    JMenu menu = new JMenu("File");
    menu.add(writeArea);
    menu.add(createAction);
    menu.add(addAction);
    menu.add(deleteAction);
    menu.add(playAction);
    menu.add(displayAction);
    menu.addSeparator();
    menu.add(exitAction);
    menuBar.add(menu);
    setJMenuBar(menuBar);

    JToolBar toolBar = new JToolBar();
    toolBar.add(writeArea);
    toolBar.add(createAction);
    toolBar.add(addAction);
    toolBar.add(deleteAction);
    toolBar.add(playAction);
    toolBar.add(displayAction);
    toolBar.add(exitAction);
    add(toolBar, BorderLayout.NORTH);

    pack();
    setVisible(true);
  }

  /**
   * @brief The main method
   * 
   * @param args The arguments
   */
  public static void main(String[] args) {
	  String host = Client.DEFAULT_HOST;
    int port = Client.DEFAULT_PORT;
    
    client = null;
    
    try {
      client = new Client(host, port);
    }
    catch (Exception ex) {
      System.err.println("Client: Couldn't connect to "+host+":"+port);
      System.exit(1);
    }
    
    System.out.println("Client connected to "+host+":"+port);

	  new MainWindow();
  }
}