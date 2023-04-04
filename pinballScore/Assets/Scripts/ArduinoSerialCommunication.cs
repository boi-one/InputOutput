using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System.IO.Ports;
using System;
using TMPro;
using UnityEngine.UI;

public class ArduinoSerialCommunication : MonoBehaviour
{
    SerialPort Serial;
    public TMP_Text ScoreText;
    public Sprite[] frames = new Sprite[4];
    public float framerate = 0.1f;
    float nextframe = 0.0f;
    public Image background;
    int length = 0;
    // Start is called before the first frame update
    void Start()
    {
        /*Serial = new SerialPort();
        Serial.PortName = "COM5";
        Serial.Parity = Parity.None;
        Serial.DataBits = 8;
        Serial.StopBits = StopBits.One;
        Serial.Open();*/
    }

    // Update is called once per frame
    void Update()
    {
        /*if(Serial.BytesToRead > 0)
        {
             string score = Convert.ToString(Serial.ReadLine());
             ScoreText.text = score;
        }*/
        if (Time.time > nextframe)
        {
            Debug.Log(length);
            if (length == 4)
                length = 0;
            background.sprite = frames[length];
            length++;
            nextframe = Time.time + framerate;
        }
        
    }
}
