// TCP Server Program in Java
import java.io.*;
import java.net.*;

public class TCPServer {
    public static void main(String[] args) {
        int port = 8080;
        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("TCP Server listening on port " + port + "...");
            Socket socket = serverSocket.accept();
            System.out.println("Client connected.");

            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

            String clientMsg = in.readLine();
            System.out.println("Client: " + clientMsg);

            out.println("Hello from TCP Server!");

            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
