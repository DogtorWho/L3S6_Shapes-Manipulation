package tcp;

import java.io.IOException;
import java.net.*;

/**
 * TCP class to create the TCP connexion of the server
 */
public class TCP {
	/**
	 * ServerSocket stocking the socket of the server
	 */
	private ServerSocket _serverSocket;
	/**
	 * int stocking the port of the server
	 */
	private int _serverPort;
	/**
	 * int stocking the local port
	 */
	private int _localPort;
	/**
	 * InetAddress stocking the server machine address
	 */
	private InetAddress _thisMachine;
	/**
	 * ThreadGroup stocking the thread of the group
	 */
	ThreadGroup _group;
	/**
	 * int stocking the connexion number
	 */
	private int _NoConnexion;
	
	public TCP(int port) throws IOException {
		_serverPort = port;
		_thisMachine = InetAddress.getLocalHost();
		_NoConnexion = 0;
	}
	
	/**
	 * method initializing the TCP for the server, creating the socket and opening the port
	 * @throws IOException for the thread
	 */
	public void open_server() throws IOException {
		_serverSocket = new ServerSocket(_serverPort);
		_localPort = _serverSocket.getLocalPort();
		_group = new ThreadGroup("clients_sockets");
		
		System.out.println("The server is now open");
	}
	
	/**
	 * method with infinite loop which listen the port and create a new client when one connects to it
	 * @throws IOException for the thread
	 */
	public void listen() throws IOException {
		while(true) {
			Socket newClientSocket;
		    ClientRequestManager newClientThread;
		    
		    newClientSocket = _serverSocket.accept();
		    _NoConnexion++;
		    System.out.println("New client connected (n°" + _NoConnexion + ")");
		    
		    newClientThread = new ClientRequestManager(newClientSocket, _group, _NoConnexion);
		    newClientThread.start();
		}
	}
	
	/**
	 * method closing the server socket
	 * @throws IOException for the thread
	 */
	public void close_server() throws IOException {
		_serverSocket.close();
		System.out.println("The server closed");
	}

	public int get_localPort() { return _localPort; }
	public InetAddress get_thisMachine() { return _thisMachine; }
	public int get_NoConnexion() { return _NoConnexion; }
}
