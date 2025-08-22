// UDP Server Program in Java
import java.net.*;

public class UDPServer {
    public static void main(String[] args) {
        int port = 8080;
        byte[] buffer = new byte[1024];

        try (DatagramSocket socket = new DatagramSocket(port)) {
            System.out.println("UDP Server listening on port " + port + "...");

            DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
            socket.receive(packet);

            String clientMsg = new String(packet.getData(), 0, packet.getLength());
            System.out.println("Client: " + clientMsg);

            String response = "Hello from UDP Server!";
            byte[] responseBytes = response.getBytes();

            DatagramPacket responsePacket =
                    new DatagramPacket(responseBytes, responseBytes.length,
                            packet.getAddress(), packet.getPort());

            socket.send(responsePacket);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
