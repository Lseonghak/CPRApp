package com.jinyeob.mythermometer;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Adapter;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.List;

public class ranking extends AppCompatActivity {
    static final String[] LIST_MENU = {"LIST1", "LIST2", "LIST3"} ;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ranking);


        Intent intent = getIntent();
        int score = intent.getExtras().getInt("score");
        String id = intent.getExtras().getString("id");

        String a = Integer.toString(score);
        String total = id+ "\n" + a + "점";

        ListView listview = findViewById(R.id.listview);
        List<String> list = new ArrayList<>();
        list.add(total);

        ArrayAdapter adapter = new ArrayAdapter(this, android.R.layout.simple_list_item_1, list);
        listview.setAdapter(adapter);



    }
}