package cc.arduino.serial;
import java.util.HashMap;

public class SerialLister {
    
	
    static {
        System.out.println(1);
        try {
            System.out.println(System.mapLibraryName("listCom"));
        System.loadLibrary("listCom");
        } catch (Exception e) {
            e.printStackTrace();
        }
        System.out.println(2);
    }
    
    
    public native HashMap[] serialPortList();
    
}