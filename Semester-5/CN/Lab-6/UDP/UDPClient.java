// UDP Client Program in Java
import java.net.*;

public class UDPClient {
    public static void main(String[] args) {
        String host = "127.0.0.1";
        int port = 8080;

        try (DatagramSocket socket = new DatagramSocket()) {
            String msg = "Hello from UDP Client!";
            byte[] buffer = msg.getBytes();

            InetAddress address = InetAddress.getByName(host);
            DatagramPacket packet = new DatagramPacket(buffer, buffer.length, address, port);
            socket.send(packet);

            byte[] recvBuffer = new byte[1024];
            DatagramPacket recvPacket = new DatagramPacket(recvBuffer, recvBuffer.length);
            socket.receive(recvPacket);

            String serverMsg = new String(recvPacket.getData(), 0, recvPacket.getLength());
            System.out.println("Server: " + serverMsg);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
