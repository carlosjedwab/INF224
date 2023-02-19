/**
 * @file ButtonAction.java
 * @author Carlos Jedwab
 * @brief Class used to create an common abstract action for a button that will send a request
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

import javax.swing.AbstractAction;
import java.awt.event.ActionEvent;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

/**
 * @brief This class is used to create an action for a button to send a request
 */
public class ButtonAction extends AbstractAction {
  private static final long serialVersionUID = 1L; /* This is used to avoid a warning */
  private JTextField writeArea; /* The text field where the user will write the request */
  private JTextArea readArea; /* The text area where the response will be displayed */
  private Client client; /* The client object */
  private String actionName; /* The name of the action for this button */

  /**
   * @brief Construct a new Button Action object
   * 
   * @param writeArea The text field where the user will write the request
   * @param readArea The text area where the response will be displayed
   * @param client The client object
   * @param actionName The name of the action
   */
  public ButtonAction(JTextField writeArea, JTextArea readArea, Client client, String actionName) {
    super(actionName);
    this.writeArea = writeArea;
    this.readArea = readArea;
    this.client = client;
    this.actionName = actionName;
  }

  /**
   * @brief This method is called when the button is pressed
   * 
   * @param e The event
   */
  @Override
  public void actionPerformed(ActionEvent e) {
    String request = this.actionName + " " + this.writeArea.getText();
    System.out.print("Request: " + request);
    String response = this.client.send(request);
    System.out.println(" Response: " + response);
    this.readArea.append(response + "\n");
  }
}