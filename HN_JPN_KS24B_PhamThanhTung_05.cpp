#include <stdio.h>


int kiem_tra_so_hoan_hao(int so) {
    int tong = 0;
    for (int i = 1; i < so; i++) {
        if (so % i == 0) {
            tong += i;
        }
    }
    return tong == so;
}


int in_mang(int mang[], int so_luong) {
    for (int i = 0; i < so_luong; i++) {
        printf("mang[%d] = %d, ", i, mang[i]);
    }
    printf("\n");
    return 0; 
}


int tim_nho_thu_2(int mang[], int so_luong) {
    if (so_luong < 2) return -1;
    int nho_nhat = mang[0];
    int nho_thu_2 = 1000000;  
    for (int i = 1; i < so_luong; i++) {
        if (mang[i] < nho_nhat) {
            nho_thu_2 = nho_nhat;
            nho_nhat = mang[i];
        } else if (mang[i] < nho_thu_2 && mang[i] > nho_nhat) {
            nho_thu_2 = mang[i];
        }
    }
    return (nho_thu_2 == 1000000) ? -1 : nho_thu_2;
}


int them_phan_tu_vao_dau(int mang[], int* so_luong, int phan_tu) {
    for (int i = *so_luong; i > 0; i--) {
        mang[i] = mang[i - 1];
    }
    mang[0] = phan_tu;
    (*so_luong)++;
    return 0; 
}


int main() {
    int mang[100], so_luong = 0;
    int lua_chon, phan_tu;

    while (1) {
        printf("\nMENU:\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Dem so luong cac so hoan hao trong mang\n");
        printf("4. Tim gia tri nho thu 2 trong mang\n");
        printf("5. Them mot phan tu vao vi tri dau trong mang\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &lua_chon);
        
        if (lua_chon == 1) {
            printf("Nhap so phan tu cua mang: ");
            scanf("%d", &so_luong);
            for (int i = 0; i < so_luong; i++) {
                printf("Nhap gia tri cho mang[%d]: ", i);
                scanf("%d", &mang[i]);
            }
        }
        
        else if (lua_chon == 2) {
            in_mang(mang, so_luong);
        }
        
        else if (lua_chon == 3) {
            int dem = 0;
            for (int i = 0; i < so_luong; i++) {
                if (kiem_tra_so_hoan_hao(mang[i])) {
                    dem++;
                }
            }
            printf("So luong cac so hoan hao trong mang: %d\n", dem);
        }
        
        else if (lua_chon == 4) {
            int nho_thu_2 = tim_nho_thu_2(mang, so_luong);
            if (nho_thu_2 == -1) {
                printf("Khong co gia tri nho thu 2 trong mang\n");
            } else {
                printf("Gia tri nho thu 2 trong mang la: %d\n", nho_thu_2);
            }
        }
        
        else if (lua_chon == 5) {
            printf("Nhap phan tu muon them vao dau mang: ");
            scanf("%d", &phan_tu);
            them_phan_tu_vao_dau(mang, &so_luong, phan_tu);
            printf("Da them phan tu vao dau mang.\n");
        }
        
        else if (lua_chon == 6) {
            printf("Thoat chuong trinh.\n");
            break;
        }
        
        else {
            printf("Lua chon khong hop le, vui long chon lai.\n");
        }
    }

    return 0;
}

