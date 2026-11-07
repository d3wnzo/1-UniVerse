package com.papayaseed.utils;

import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class SceneController {

    public static void changeScene(String fxmlName, String title) {
        try {
            FXMLLoader loader = new FXMLLoader(SceneController.class.getResource("/com/papayaseed/views/" + fxmlName));
            Parent root = loader.load();

            Stage stage = (Stage) javafx.stage.Screen.getPrimary().getOutputScaleX(); // will overwrite soon
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
