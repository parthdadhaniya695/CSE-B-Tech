// TCP Client Program in Java
import java.io.*;
import java.net.*;

public class TCPClient {
    public static void main(String[] args) {
        String host = "127.0.0.1";
        int port = 8080;

        try (Socket socket = new Socket(host, port)) {
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            out.println("Hello from TCP Client!");
            String serverMsg = in.readLine();
            System.out.println("Server: " + serverMsg);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
