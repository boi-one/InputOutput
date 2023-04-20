using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System.IO.Ports;
using System;
using TMPro;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
using UnityEngine.SocialPlatforms.Impl;

public class ArduinoSerialCommunication : MonoBehaviour
{
    SerialPort Serial;
    public TMP_Text ScoreText;
    public TMP_Text BallsText;
    public Sprite[] frames = new Sprite[4];
    public float framerate = 0.1f;
    float nextframe = 0.0f;
    public Image background;
    int length = 0;
    int highscore;
    // Start is called before the first frame update
    void Start()
    {
        Serial = new SerialPort();
        Serial.PortName = "COM5";
        Serial.Parity = Parity.None;
        Serial.DataBits = 8;
        Serial.StopBits = StopBits.One;
        Serial.Open();
    }

    // Update is called once per frame
    void Update()
    {
        if(Serial.BytesToRead > 0)
        {
            string[] info = Serial.ReadLine().Split(' ');
            string ballCount = Serial.ReadLine();
             ScoreText.text = info[0];
            BallsText.text = info[1];
            if (int.Parse(info[1]) < 0)
                SceneManager.LoadScene(1);
            Debug.Log(info[1]);
            PlayerPrefs.SetInt("score", Int32.Parse(info[0]));
            if (Int32.Parse(info[0]) > PlayerPrefs.GetInt("highscore", 0))
                PlayerPrefs.SetInt("highscore", Int32.Parse(info[0]));
        }
        if (Time.time > nextframe)
        {
            if (length == 4)
                length = 0;
            background.sprite = frames[length];
            length++;
            nextframe = Time.time + framerate;
        }
    }
}
