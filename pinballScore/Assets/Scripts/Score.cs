using System;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class Score : MonoBehaviour
{
    public TMP_Text scoreText;
    // Start is called before the first frame update
    void Start()
    {
        scoreText.text = $"GAME OVER\nSCORE:\n{PlayerPrefs.GetInt("score")}\nHIGHSCORE:\n{PlayerPrefs.GetInt("highscore")}";
    }

    void GoToScoreMenu()
    {
        SceneManager.LoadScene(0);
    }
}
