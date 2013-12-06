package cc.arduino.packages.discoverers;
import java.util.HashMap;

public class SerialLister {
    
	
    static {
	
        try {
        System.mapLibraryName("listCom");
        System.loadLibrary("listCom");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    
    public native HashMap[] serialPortList();
    
}