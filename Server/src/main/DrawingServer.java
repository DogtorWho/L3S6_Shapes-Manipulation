package main;

import tcp.TCP;

/**
 * main class of the server, which draw the shapes sended by the client
 */
public class DrawingServer {
	public static void main(String[] args)throws Exception {
		TCP server = new TCP(9111);
		
		server.open_server();
		
		// infinite loop
		server.listen();
		
		server.close_server();
	}
}