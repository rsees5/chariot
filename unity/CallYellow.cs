using UnityEngine;
using System.Collections;
using System;

public class CallYellow : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

    void OnMouseDown() {
	 	print("Clicked");
	 	Sending.sendYellow();
    }

}
