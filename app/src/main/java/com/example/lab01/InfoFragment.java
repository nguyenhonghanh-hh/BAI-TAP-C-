package com.example.lab01; // LƯU Ý: Đổi dòng này thành tên package của bạn

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

public class InfoFragment extends Fragment {
    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        // Nạp file giao diện bai4_frag_thongtin.xml
        return inflater.inflate(R.layout.bai4_frag_thongtin, container, false);
    }
}