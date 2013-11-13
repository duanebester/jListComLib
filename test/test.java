import cc.arduino.serial.SerialLister;
import java.util.HashMap;

public class test {
    
    public static void main(String[] args) {
                      
        SerialLister lister = new SerialLister();
        HashMap[] arr = lister.serialPortList();
        int i=0;
        for( i = 0; i < arr.length ; i++){
            
            System.out.println(arr[i].get("port"));
            
        }
                
    }
    
}