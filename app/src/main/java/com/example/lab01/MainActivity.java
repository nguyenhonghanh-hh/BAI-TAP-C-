package com.example.lab01;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;

public class MainActivity extends AppCompatActivity {

    // Khai báo 3 nút bấm
    Button btnInfo, btnHistory, btnSettings;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        // Nhớ đổi thành R.layout.bai4 để hiển thị đúng giao diện Bài 4
        setContentView(R.layout.bai4_main);

        // Ánh xạ (tìm) các nút bấm từ file XML sang Java dựa vào ID
        btnInfo = findViewById(R.id.btnInfo);
        btnHistory = findViewById(R.id.btnHistory);
        btnSettings = findViewById(R.id.btnSettings);

        // Mặc định khi vừa mở app, cho hiển thị luôn Tab Thông tin
        loadFragment(new InfoFragment());

        // Cài đặt sự kiện: Bấm nút nào thì gọi hàm loadFragment tương ứng
        btnInfo.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                loadFragment(new InfoFragment());
            }
        });

        btnHistory.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                loadFragment(new HistoryFragment());
            }
        });

        btnSettings.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                loadFragment(new SettingsFragment());
            }
        });
    }

    // Hàm dùng chung để thay thế Fragment vào khung (FrameLayout)
    private void loadFragment(Fragment fragment) {
        getSupportFragmentManager()
                .beginTransaction()
                .replace(R.id.fragmentContainer, fragment) // R.id.fragmentContainer là ID của cái khung trong file XML
                .commit(); // Xác nhận thực hiện đổi
    }
}