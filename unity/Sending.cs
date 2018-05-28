using UnityEngine;
using System.IO.Ports;
using System;

public class Sending : MonoBehaviour {
    
	public static SerialPort sp = new SerialPort("COM5", 9600, Parity.None, 8, StopBits.One);
	public string message2;

    void Start () {
		if (sp.IsOpen)
        {
            //sp.Close();
            //print("Closing port, because it was already open!");
        }
        else
        {
            sp.ReadTimeout = 16;  // sets the timeout value before reporting error
            try
            {
                sp.Open();
            }
            catch (Exception) {
            }
            print("Port Opened!");
        }
    }
	
	// Update is called once per frame
	void Update () {
        try {
            message2 = sp.ReadLine();
            print(message2);
        }
        catch (Exception) {

        }
	}

    void OnApplicationQuit() 
    {
       sp.Close();
    }

    public static void sendYellow(){
    	sp.Write("y");
    }

    public static void sendGreen(){
    	sp.Write("g");
    }

    public static void sendRed(){
    	sp.Write("r");
    }

}
