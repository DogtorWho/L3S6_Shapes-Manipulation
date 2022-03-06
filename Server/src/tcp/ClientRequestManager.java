package tcp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

import expert.ExpertCircle;
import expert.ExpertPolygon;
import expert.ExpertSegment;
import expert.ExpertShape;
import expert.ExpertTriangle;
import draw.swing.DrawSwing;

/**
 * ClientRequestManager class extending the Thread class to instanciate the clients
 */
public class ClientRequestManager extends Thread {
	/**
	 * Socket stocking the socket of the thread
	 */
	Socket _socket;
	/**
	 * int stocking the connexion number
	 */
	int _NoConnexion;
	/**
	 * BufferedReader stocking the string send by the client to the thread via TCP
	 */
	BufferedReader _inputStream;
		
	public ClientRequestManager(Socket socket, ThreadGroup group, int NoConnexion) throws IOException {
		super(group, "ClientRequestManager");

		this._socket = socket;
		this._NoConnexion = NoConnexion;

		_inputStream = new BufferedReader(new InputStreamReader(this._socket.getInputStream()));
	}
	
	/**
	 * main method of the thread drawing the shape send by the client
	 */
	public void run() {
		String message;
		DrawSwing drawingTool = new DrawSwing(480, 320);

		try {
			while(!isInterrupted()) {
				message = _inputStream.readLine();
				if(message != null) {
					System.out.println(" Client n°" + this._NoConnexion + " send : ");
					System.out.println(message);
					
					ExpertShape expert;
					expert = new ExpertPolygon(null);
					expert = new ExpertCircle(expert);
					expert = new ExpertTriangle(expert);
					expert = new ExpertSegment(expert);

					if(!expert.resolve(message, drawingTool))
						System.out.println("Incorrect string format");
					
					sleep(1);
				}
			}
		}
		catch(InterruptedException error) { /* thread interrupted */ }
		catch(IOException error) { System.err.println("Client socket is invalid"); }
	}
}
