import pygame
import random
import sys
import time
import math
import os

def resource_path(relative_path):
    """ Dapatkan path absolut ke resource, bekerja untuk dev dan untuk PyInstaller """
    try:
        # PyInstaller membuat folder sementara dan menyimpan path-nya di _MEIPASS
        base_path = sys._MEIPASS
    except Exception:
        base_path = os.path.abspath(".")

    return os.path.join(base_path, relative_path)

pygame.init()
pygame.mixer.init()
SCREEN_WIDTH = 1280
SCREEN_HEIGHT = 720
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Algorithm Battle Visualizer by BONTENG")
clock = pygame.time.Clock()

try:
    music_file = resource_path("musikk.ogg") 
    pygame.mixer.music.load(music_file)                
    pygame.mixer.music.set_volume(0.2)      
    pygame.mixer.music.play(-1)               
except pygame.error as e:
    print(f"Tidak bisa memuat musik: {e}")

# 2. Definisikan Warna
PURPLE_BG = (42, 9, 68); MAGENTA_NEON = (248, 6, 204); CYAN_NEON = (0, 246, 248)
YELLOW_NEON = (245, 210, 24); WHITE = (255, 255, 255); GREEN = (0, 255, 127)
DARK_BLUE = (30, 144, 255); BLUE = (65, 105, 225); RED = (255, 0, 0)
GREY = (50, 50, 50); BLACK = (0,0,0)

# 3. Pengaturan Font
title_font = pygame.font.SysFont("Arial", 72, bold=True)
subtitle_font = pygame.font.SysFont("Arial", 60, bold=True)
button_font = pygame.font.SysFont("Arial", 50)
analysis_title_font = pygame.font.SysFont("Arial", 40, bold=True)
analysis_text_font = pygame.font.SysFont("Arial", 20)
arena_font = pygame.font.SysFont("Arial", 30, bold=True)
small_font = pygame.font.SysFont("Arial", 24)
smaller_font = pygame.font.SysFont("Arial", 18)
credit_font = pygame.font.SysFont("Arial", 28, bold=True)
nim_font = pygame.font.SysFont("Arial", 24)
creator_font = pygame.font.SysFont("Arial", 20, italic=True)
winner_font = pygame.font.SysFont("Arial", 50, bold=True)


# ===============================================================
# FUNGSI & KELAS BANTUAN
# ===============================================================
def draw_text(text, font, color, surface, x, y, align="center"):
    text_obj = font.render(text, True, color)
    text_rect = text_obj.get_rect({align: (x, y)})
    surface.blit(text_obj, text_rect)

class AnimatedBackground:
    def _init_(self):
        self.stars = [self.Star() for _ in range(150)]
        self.lines = [self.Line() for _ in range(50)]
    def update_and_draw(self, surface):
        for element in self.stars + self.lines:
            element.update(surface); element.draw(surface)
    class Star:
        def _init_(self): self.x=random.randint(0,SCREEN_WIDTH); self.y=random.randint(0,SCREEN_HEIGHT); self.speed=random.randint(1,3); self.radius=random.randint(1,2)
        def update(self, s): self.y+=self.speed; self.reset(s)
        def draw(self, s): pygame.draw.circle(s, MAGENTA_NEON, (int(self.x), int(self.y)), int(self.radius))
        def reset(self, s):
            if self.y > SCREEN_HEIGHT: self.y=0; self.x=random.randint(0,SCREEN_WIDTH)
    class Line:
        def _init_(self): self.x=random.randint(0,SCREEN_WIDTH); self.y=random.randint(-SCREEN_HEIGHT,0); self.speed=random.randint(4,10); self.length=random.randint(50,150)
        def update(self, s): self.y+=self.speed; self.reset(s)
        def draw(self, s): pygame.draw.line(s, CYAN_NEON, (int(self.x),int(self.y)), (int(self.x),int(self.y+self.length)), 1)
        def reset(self, s):
            if self.y > SCREEN_HEIGHT: self.y=random.randint(-SCREEN_HEIGHT,0); self.x=random.randint(0,SCREEN_WIDTH)

def generate_random_array(size, min_val, max_val):
    return [random.randint(min_val, max_val) for _ in range(size)]
def generate_sorted_array(size, min_val, max_val, spacing='uniform'):
    arr = []
    if spacing == 'uniform':
        if size > 1: arr = [min_val + int(i * (max_val - min_val) / (size -1)) for i in range(size)]
        elif size == 1: arr = [min_val]
    else: # 'skewed'
        arr = [random.randint(min_val, max_val) for _ in range(size)]; arr.sort()
    return arr

# ===============================================================
# ALGORITMA-ALGORITMA
# ===============================================================
def merge_sort_generator(array, start, end):
    if end - start > 1:
        middle = (start + end) // 2
        yield from merge_sort_generator(array, start, middle)
        yield from merge_sort_generator(array, middle, end)
        left = array[start:middle]; right = array[middle:end]
        a=0; b=0; c=start
        while a<len(left) and b<len(right):
            if left[a]<right[b]: array[c]=left[a]; a+=1
            else: array[c]=right[b]; b+=1
            yield array,{c:DARK_BLUE}
            c+=1
        while a<len(left): array[c]=left[a]; a+=1; yield array,{c:DARK_BLUE}; c+=1
        while b<len(right): array[c]=right[b]; b+=1; yield array,{c:DARK_BLUE}; c+=1
def quick_sort_generator(array, low, high):
    stack=[(low,high)]
    while stack:
        low,high=stack.pop()
        if low<high:
            partition_gen=partition_generator(array,low,high)
            pivot_index=-1
            while True:
                try: yield next(partition_gen)
                except StopIteration as e: pivot_index=e.value; break
            if pivot_index!=-1: stack.append((low,pivot_index-1)); stack.append((pivot_index+1,high))
def partition_generator(array, low, high):
    pivot=array[high]; i=low-1
    for j in range(low,high):
        yield array,{j:DARK_BLUE,high:YELLOW_NEON}
        if array[j]<=pivot: i+=1; array[i],array[j]=array[j],array[i]; yield array,{i:GREEN,j:DARK_BLUE}
    array[i+1],array[high]=array[high],array[i+1]; yield array,{i+1:GREEN,high:DARK_BLUE}
    return i+1
def merge_sort_standard(arr):
    if len(arr)>1:
        mid=len(arr)//2; L=arr[:mid]; R=arr[mid:]; merge_sort_standard(L); merge_sort_standard(R)
        i=j=k=0
        while i<len(L) and j<len(R):
            if L[i]<R[j]: arr[k]=L[i]; i+=1
            else: arr[k]=R[j]; j+=1
            k+=1
        while i<len(L): arr[k]=L[i]; i+=1; k+=1
        while j<len(R): arr[k]=R[j]; j+=1; k+=1
def quick_sort_standard(arr,low,high):
    if low<high: pi=partition_standard(arr,low,high); quick_sort_standard(arr,low,pi-1); quick_sort_standard(arr,pi+1,high)
def partition_standard(arr,low,high):
    pivot=arr[high]; i=low-1
    for j in range(low,high):
        if arr[j]<=pivot: i=i+1; arr[i],arr[j]=arr[j],arr[i]
    arr[i+1],arr[high]=arr[high],arr[i+1]
    return i+1
def binary_search_generator(arr,target):
    low,high=0,len(arr)-1; steps=0
    while low<=high:
        mid=(low+high)//2; steps+=1; yield steps,(low,high),mid,-1
        if arr[mid]==target: yield steps,(low,high),mid,mid; return
        elif arr[mid]<target: low=mid+1
        else: high=mid-1
    yield steps,(low,high),-1,-1
def interpolation_search_generator(arr, target):
    low, high = 0, len(arr) - 1
    steps = 0
    
    while low <= high and target >= arr[low] and target <= arr[high]:
        steps += 1
        
        # Handle kasus dimana low == high
        if low == high:
            yield steps, (low, high), low, -1
            if arr[low] == target:
                yield steps, (low, high), low, low
            return
        
        # CEK: Hindari division by zero
        if arr[high] == arr[low]:
            # Semua elemen dalam range sama
            yield steps, (low, high), low, -1
            if arr[low] == target:
                yield steps, (low, high), low, low
            return
        
        # Rumus interpolation search yang benar
        pos = low + ((target - arr[low]) * (high - low)) // (arr[high] - arr[low])
        
        # Pastikan posisi tidak keluar dari bounds
        if pos < low:
            pos = low
        if pos > high:
            pos = high
            
        yield steps, (low, high), pos, -1
        
        if arr[pos] == target:
            yield steps, (low, high), pos, pos
            return
            
        if arr[pos] < target:
            low = pos + 1
        else:
            high = pos - 1
            
    yield steps, (low, high), -1, -1
def binary_search_standard(arr,target):
    low,high=0,len(arr)-1; steps=0
    while low<=high:
        mid=(low+high)//2; steps+=1
        if arr[mid]==target: return mid,steps
        elif arr[mid]<target: low=mid+1
        else: high=mid-1
    return-1,steps
def interpolation_search_standard(arr, target):
    low, high = 0, len(arr) - 1
    steps = 0
    
    while low <= high and target >= arr[low] and target <= arr[high]:
        steps += 1
        
        if low == high:
            if arr[low] == target:
                return low, steps
            return -1, steps
        
        # CEK: Hindari division by zero
        if arr[high] == arr[low]:
            # Semua elemen dalam range sama
            if arr[low] == target:
                return low, steps
            return -1, steps
        
        # Perbaikan rumus interpolation
        pos = low + ((target - arr[low]) * (high - low)) // (arr[high] - arr[low])
        
        # Boundary check
        if pos < low or pos > high:
            break
            
        if arr[pos] == target:
            return pos, steps
            
        if arr[pos] < target:
            low = pos + 1
        else:
            high = pos - 1
            
    return -1, steps

# ===============================================================
# FUNGSI UNTUK MENGGAMBAR ELEMEN ARENA
# ===============================================================
def draw_bars(surface, array, x_offset, y_offset, arena_width, arena_height, max_val, color_map={}, finished_color=None):
    if not array: return
    bar_width = arena_width / len(array)
    for i, value in enumerate(array):
        bar_height = (value / max_val) * arena_height if max_val > 0 else 0
        bar_x = x_offset + i * bar_width
        bar_y = y_offset + (arena_height - bar_height)
        bar_visual_width = max(1, bar_width - 1)
        color = finished_color if finished_color else color_map.get(i, CYAN_NEON)
        pygame.draw.rect(surface, color, (int(bar_x), int(bar_y), int(bar_visual_width), int(bar_height)))

def draw_search_grid(surface, array, rect, state, found_idx, is_finished):
    if not array: return
    cols = 25
    rows = math.ceil(len(array) / cols)
    cell_width = rect.width / cols
    cell_height = rect.height / rows

    for i, val in enumerate(array):
        row = i // cols
        col = i % cols
        cell_rect = pygame.Rect(rect.x + col * cell_width, rect.y + row * cell_height, cell_width, cell_height)
        color = WHITE
        if is_finished and i != found_idx: color = GREY
        elif 'range' in state and state.get('range') and not (state['range'][0] <= i <= state['range'][1]): color = GREY
        if i == found_idx: color = GREEN
        elif 'probe' in state and i == state['probe']: color = RED
        pygame.draw.rect(surface, color, cell_rect)
        pygame.draw.rect(surface, BLACK, cell_rect, 1)
        if cell_width > 30 and cell_height > 20:
            draw_text(str(val), smaller_font, BLACK, surface, cell_rect.centerx, cell_rect.centery)

# ===============================================================
# KELAS-KELAS UNTUK SETIAP LAYAR (ARSITEKTUR BARU & STABIL)
# ===============================================================

class MainMenu:
    def _init_(self):
        self.selected_button_index = 0
        self.button_start = pygame.Rect(SCREEN_WIDTH//2-150, 380, 300, 70)
        self.button_credit = pygame.Rect(SCREEN_WIDTH//2-150, 480, 300, 70)
        self.button_quit = pygame.Rect(SCREEN_WIDTH//2-150, 580, 300, 70)
        self.buttons = [self.button_start, self.button_credit, self.button_quit]
        self.button_texts = ["Mulai", "Credit", "Keluar"]
    
    def run(self, surface, events, bg):
        mx, my = pygame.mouse.get_pos()
        
        # Reset dulu, baru cek hover
        self.selected_button_index = -1
        for i, button in enumerate(self.buttons):
            if button.collidepoint((mx, my)): 
                self.selected_button_index = i
        
        for event in events:
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_DOWN: 
                    self.selected_button_index = (self.selected_button_index + 1) % len(self.buttons)
                if event.key == pygame.K_UP: 
                    self.selected_button_index = (self.selected_button_index - 1 + len(self.buttons)) % len(self.buttons)
                if event.key == pygame.K_RETURN:
                    if self.selected_button_index == 0: return 'selection'
                    if self.selected_button_index == 1: return 'credits'
                    if self.selected_button_index == 2: return 'quit'
            
            if event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
                if self.button_start.collidepoint((mx, my)): return 'selection'
                if self.button_credit.collidepoint((mx, my)): return 'credits'
                if self.button_quit.collidepoint((mx, my)): return 'quit'
        
        bg.update_and_draw(surface)
        draw_text("Algorithm Battle Visualizer", title_font, WHITE, surface, SCREEN_WIDTH/2, 150)
        draw_text("BONTENG", subtitle_font, YELLOW_NEON, surface, SCREEN_WIDTH/2, 250)
        
        for i, button in enumerate(self.buttons):
            color = YELLOW_NEON if i == self.selected_button_index else MAGENTA_NEON
            pygame.draw.rect(surface, color, button, 3, border_radius=15)
            draw_text(self.button_texts[i], button_font, WHITE, surface, button.centerx, button.centery)
        
        return None

class CreditsScreen:
    def _init_(self):
        self.members = [
            ("Akmal Alief Ramadhan", "4524210128"),
            ("Muhammad Faris Fahreza", "4524210062"), 
            ("Nayunda Krisna Abipasia", "4524210077"),
            ("Railene Akbillah R. H.", "4524210081")
        ]
        self.button_back = pygame.Rect(SCREEN_WIDTH//2-150, 600, 300, 70)
    
    def run(self, surface, events, bg):
        mx, my = pygame.mouse.get_pos()
        back_button_hover = self.button_back.collidepoint((mx, my))
        
        for event in events:
            if event.type == pygame.QUIT:
                return 'quit'
            if (event.type == pygame.KEYDOWN and (event.key == pygame.K_RETURN or event.key == pygame.K_ESCAPE)): 
                return 'main_menu'
            if (event.type == pygame.MOUSEBUTTONDOWN and event.button == 1 and back_button_hover): 
                return 'main_menu'
        
        bg.update_and_draw(surface)
        
        # Judul Credits
        draw_text("Credits", title_font, WHITE, surface, SCREEN_WIDTH/2, 150)
        
        # Kotak anggota tim
        box_width = 280
        box_height = 180 
        gap = 30
        total_width = (4 * box_width) + (3 * gap)
        start_x = (SCREEN_WIDTH - total_width) / 2
        
        for i, (name, nim) in enumerate(self.members):
            box_x = start_x + i * (box_width + gap)
            member_box = pygame.Rect(int(box_x), 300, box_width, box_height)
            pygame.draw.rect(surface, MAGENTA_NEON, member_box, 3, border_radius=15)
            
            name_parts = name.split()
            if "Railene" in name:
                draw_text(name_parts[0], credit_font, WHITE, surface, member_box.centerx, member_box.centery-55)
                draw_text(" ".join(name_parts[1:]), credit_font, WHITE, surface, member_box.centerx, member_box.centery-25)
                draw_text(nim, nim_font, YELLOW_NEON, surface, member_box.centerx, member_box.centery+10)
                draw_text("Creator", creator_font, GREEN, surface, member_box.centerx, member_box.centery+40)
            elif len(name_parts) > 2:
                draw_text(name_parts[0], credit_font, WHITE, surface, member_box.centerx, member_box.centery-40)
                draw_text(" ".join(name_parts[1:]), credit_font, WHITE, surface, member_box.centerx, member_box.centery-10)
                draw_text(nim, nim_font, YELLOW_NEON, surface, member_box.centerx, member_box.centery+30)
            else:
                draw_text(name, credit_font, WHITE, surface, member_box.centerx, member_box.centery-20)
                draw_text(nim, nim_font, YELLOW_NEON, surface, member_box.centerx, member_box.centery+20)
        
        # Tombol kembali dengan hover effect
        back_color = YELLOW_NEON if back_button_hover else MAGENTA_NEON
        pygame.draw.rect(surface, back_color, self.button_back, 3, border_radius=15)
        draw_text("Kembali", button_font, WHITE, surface, self.button_back.centerx, self.button_back.centery)
        

class SelectionMenu:
    def _init_(self):
        self.selected_button_index = 0
        self.button_sorting = pygame.Rect(SCREEN_WIDTH//2-250, 300, 500, 80)
        self.button_searching = pygame.Rect(SCREEN_WIDTH//2-250, 420, 500, 80)
        self.button_back = pygame.Rect(SCREEN_WIDTH//2-250, 540, 500, 80)
        self.buttons = [self.button_sorting, self.button_searching, self.button_back]
        self.button_texts = ["Pertarungan Sorting", "Balapan Searching", "Kembali"]
    
    def run(self, surface, events, bg):
        mx, my = pygame.mouse.get_pos()
        
        # Reset dulu, baru cek hover
        self.selected_button_index = -1
        for i, button in enumerate(self.buttons):
            if button.collidepoint((mx, my)): 
                self.selected_button_index = i
        
        for event in events:
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_DOWN: 
                    self.selected_button_index = (self.selected_button_index + 1) % len(self.buttons)
                if event.key == pygame.K_UP: 
                    self.selected_button_index = (self.selected_button_index - 1 + len(self.buttons)) % len(self.buttons)
                if event.key == pygame.K_RETURN:
                    if self.selected_button_index == 0: return 'sorting_mode_selection'
                    if self.selected_button_index == 1: return 'searching_mode_selection'
                    if self.selected_button_index == 2: return 'main_menu'
            
            if event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
                if self.button_sorting.collidepoint((mx, my)): return 'sorting_mode_selection'
                if self.button_searching.collidepoint((mx, my)): return 'searching_mode_selection'
                if self.button_back.collidepoint((mx, my)): return 'main_menu'
        
        bg.update_and_draw(surface)
        draw_text("Pilih Arena", title_font, WHITE, surface, SCREEN_WIDTH/2, 150)
        
        for i, button in enumerate(self.buttons):
            color = YELLOW_NEON if i == self.selected_button_index else MAGENTA_NEON
            pygame.draw.rect(surface, color, button, 3, border_radius=15)
            draw_text(self.button_texts[i], button_font, WHITE, surface, button.centerx, button.centery)
        
        return None

class SortingModeSelection:
    def _init_(self):
        self.selected_button_index = 0
        self.button_anim = pygame.Rect(SCREEN_WIDTH//2-250, 300, 500, 80)
        self.button_no_anim = pygame.Rect(SCREEN_WIDTH//2-250, 420, 500, 80)
        self.button_back = pygame.Rect(SCREEN_WIDTH//2-250, 540, 500, 80)
        self.buttons = [self.button_anim, self.button_no_anim, self.button_back]
        self.button_texts = ["Dengan Animasi", "Tanpa Animasi", "Kembali"]
    
    def run(self, surface, events, bg):
        mx, my = pygame.mouse.get_pos()
        
        # Reset dulu, baru cek hover
        self.selected_button_index = -1
        for i, button in enumerate(self.buttons):
            if button.collidepoint((mx, my)): 
                self.selected_button_index = i
        
        for event in events:
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_DOWN: 
                    self.selected_button_index = (self.selected_button_index + 1) % len(self.buttons)
                if event.key == pygame.K_UP: 
                    self.selected_button_index = (self.selected_button_index - 1 + len(self.buttons)) % len(self.buttons)
                if event.key == pygame.K_RETURN:
                    if self.selected_button_index == 0: return 'sorting_battle_animated'
                    if self.selected_button_index == 1: return 'sorting_battle_instant'
                    if self.selected_button_index == 2: return 'selection'
            
            if event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
                if self.button_anim.collidepoint((mx, my)): return 'sorting_battle_animated'
                if self.button_no_anim.collidepoint((mx, my)): return 'sorting_battle_instant'
                if self.button_back.collidepoint((mx, my)): return 'selection'
        
        bg.update_and_draw(surface)
        draw_text("Pilih Mode Sorting", title_font, WHITE, surface, SCREEN_WIDTH/2, 150)
        
        for i, button in enumerate(self.buttons):
            color = YELLOW_NEON if i == self.selected_button_index else MAGENTA_NEON
            pygame.draw.rect(surface, color, button, 3, border_radius=15)
            draw_text(self.button_texts[i], button_font, WHITE, surface, button.centerx, button.centery)
        
        return None

class SearchingModeSelection:
    def _init_(self):
        self.selected_button_index = 0
        self.button_anim = pygame.Rect(SCREEN_WIDTH//2-250, 300, 500, 80)
        self.button_no_anim = pygame.Rect(SCREEN_WIDTH//2-250, 420, 500, 80)
        self.button_back = pygame.Rect(SCREEN_WIDTH//2-250, 540, 500, 80)
        self.buttons = [self.button_anim, self.button_no_anim, self.button_back]
        self.button_texts = ["Dengan Animasi", "Tanpa Animasi", "Kembali"]
    
    def run(self, surface, events, bg):
        mx, my = pygame.mouse.get_pos()
        
        # Reset dulu, baru cek hover
        self.selected_button_index = -1
        for i, button in enumerate(self.buttons):
            if button.collidepoint((mx, my)): 
                self.selected_button_index = i
        
        for event in events:
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_DOWN: 
                    self.selected_button_index = (self.selected_button_index + 1) % len(self.buttons)
                if event.key == pygame.K_UP: 
                    self.selected_button_index = (self.selected_button_index - 1 + len(self.buttons)) % len(self.buttons)
                if event.key == pygame.K_RETURN:
                    if self.selected_button_index == 0: return 'searching_race_animated'
                    if self.selected_button_index == 1: return 'searching_race_instant'
                    if self.selected_button_index == 2: return 'selection'
            
            if event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
                if self.button_anim.collidepoint((mx, my)): return 'searching_race_animated'
                if self.button_no_anim.collidepoint((mx, my)): return 'searching_race_instant'
                if self.button_back.collidepoint((mx, my)): return 'selection'
        
        bg.update_and_draw(surface)
        draw_text("Pilih Mode Searching", title_font, WHITE, surface, SCREEN_WIDTH/2, 150)
        
        for i, button in enumerate(self.buttons):
            color = YELLOW_NEON if i == self.selected_button_index else MAGENTA_NEON
            pygame.draw.rect(surface, color, button, 3, border_radius=15)
            draw_text(self.button_texts[i], button_font, WHITE, surface, button.centerx, button.centery)
        
        return None

class AnalysisScreen:
    def _init_(self, is_sorting):
        self.is_sorting = is_sorting
        self.selected_button_index = 0
        self.button_back_arena = pygame.Rect(50, 650, 350, 50)
        self.button_menu = pygame.Rect(SCREEN_WIDTH//2-175, 650, 350, 50)
        self.button_next_arena = pygame.Rect(SCREEN_WIDTH - 400, 650, 350, 50)
        self.buttons = [self.button_back_arena, self.button_menu, self.button_next_arena]
    
    def run(self, surface, events, bg, results):
        mx, my = pygame.mouse.get_pos()
        
        # Reset dulu, baru cek hover
        self.selected_button_index = -1
        for i, button in enumerate(self.buttons):
            if button.collidepoint((mx, my)): 
                self.selected_button_index = i
        
        for event in events:
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RIGHT: 
                    self.selected_button_index = (self.selected_button_index + 1) % len(self.buttons)
                if event.key == pygame.K_LEFT: 
                    self.selected_button_index = (self.selected_button_index - 1 + len(self.buttons)) % len(self.buttons)
                if event.key == pygame.K_RETURN:
                    if self.selected_button_index == 0: return 'back_to_battle'
                    if self.selected_button_index == 1: return 'main_menu'
                    if self.selected_button_index == 2:
                        return 'searching_mode_selection' if self.is_sorting else 'sorting_mode_selection'
            
            if event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
                if self.button_back_arena.collidepoint((mx, my)): return 'back_to_battle'
                if self.button_menu.collidepoint((mx, my)): return 'main_menu'
                if self.button_next_arena.collidepoint((mx, my)): 
                    return 'searching_mode_selection' if self.is_sorting else 'sorting_mode_selection'
        
        bg.update_and_draw(surface)
        
        if self.is_sorting: 
            self.draw_sorting_analysis(surface, results)
        else: 
            self.draw_searching_analysis(surface, results)
        
        # Gambar buttons dengan hover effect
        for i, button in enumerate(self.buttons):
            color = YELLOW_NEON if i == self.selected_button_index else MAGENTA_NEON
            pygame.draw.rect(surface, color, button, 3, border_radius=15)
        
        draw_text("Kembali ke Arena", small_font, WHITE, surface, self.button_back_arena.centerx, self.button_back_arena.centery)
        draw_text("Kembali ke Menu", small_font, WHITE, surface, self.button_menu.centerx, self.button_menu.centery)
        
        next_text = "Lanjut ke Balapan" if self.is_sorting else "Lanjut ke Pertarungan"
        draw_text(next_text, small_font, WHITE, surface, self.button_next_arena.centerx, self.button_next_arena.centery)
        
        return None

    def draw_sorting_analysis(self, surface, results):
        draw_text("Merge Sort", analysis_title_font, MAGENTA_NEON, surface, SCREEN_WIDTH*0.25, 50, "center")
        merge_text = [
            "Prinsip: 'Pecah dan Taklukkan'.",
            "Membagi data, lalu menggabungkan",
            "kembali sambil mengurutkan.",
            "",
            "Kompleksitas Waktu:",
            "- Best, Avg, Worst: O(n log n)",
            "",
            "Karakteristik:",
            "Sangat STABIL, performa konsisten,",
            "tapi butuh memori tambahan."
        ]
        for i, line in enumerate(merge_text): 
            draw_text(line, analysis_text_font, WHITE, surface, 50, 120 + i * 28, "topleft")
        
        draw_text("Quick Sort", analysis_title_font, CYAN_NEON, surface, SCREEN_WIDTH*0.75, 50, "center")
        quick_text = [
            "Prinsip: Partisi berdasarkan 'pivot'.",
            "Memindahkan elemen berdasarkan",
            "nilai pivot secara rekursif.",
            "",
            "Kompleksitas Waktu:",
            "- Best, Avg: O(n log n)",
            "- Worst: O(n²)",
            "",
            "Karakteristik:",
            "Sangat CEPAT (in-place),",
            "tapi performa anjlok di data terurut."
        ]
        for i, line in enumerate(quick_text): 
            draw_text(line, analysis_text_font, WHITE, surface, SCREEN_WIDTH/2 + 50, 120 + i * 28, "topleft")
        
        draw_text("Kesimpulan Battle", analysis_title_font, YELLOW_NEON, surface, SCREEN_WIDTH/2, 480)
        analysis_summary = [
            "Pada 'Data Acak', Quick Sort umumnya menang karena efisiensi memori & overhead rendah.", 
            "Pada 'Data Terurut', Quick Sort mengalami skenario terburuk dan menjadi sangat lambat,", 
            "sementara performa Merge Sort tetap stabil dan unggul."
        ]
        for i, line in enumerate(analysis_summary): 
            draw_text(line, analysis_text_font, WHITE, surface, SCREEN_WIDTH/2, 530 + i * 30)

    def draw_searching_analysis(self, surface, results):
        draw_text("Binary Search", analysis_title_font, MAGENTA_NEON, surface, SCREEN_WIDTH * 0.25, 50, "center")
        binary_text = [
            "Prinsip: 'Bagi Dua'.",
            "Selalu memeriksa elemen tengah,",
            "lalu membuang setengah data.",
            "",
            "Kompleksitas Waktu:",
            "- Best: O(1)",
            "- Avg, Worst: O(log n)",
            "",
            "Karakteristik:",
            "Sangat cepat dan efisien.",
            "Wajib untuk data terurut."
        ]
        for i, line in enumerate(binary_text): 
            draw_text(line, analysis_text_font, WHITE, surface, 50, 120 + i * 28, "topleft")
        
        draw_text("Interpolation Search", analysis_title_font, CYAN_NEON, surface, SCREEN_WIDTH * 0.75, 50, "center")
        inter_text = [
            "Prinsip: 'Tebakan Cerdas'.",
            "Memperkirakan posisi data berdasarkan",
            "nilainya (seperti cari di kamus).",
            "",
            "Kompleksitas Waktu:",
            "- Best: O(1)",
            "- Avg: O(log log n)", 
            "- Worst: O(n)",
            "",
            "Karakteristik:",
            "Lebih cepat dari Binary Search, TAPI",
            "hanya untuk data terdistribusi seragam."
        ]
        for i, line in enumerate(inter_text): 
            draw_text(line, analysis_text_font, WHITE, surface, SCREEN_WIDTH/2 + 50, 120 + i * 28, "topleft")
        
        draw_text("Kesimpulan Battle", analysis_title_font, YELLOW_NEON, surface, SCREEN_WIDTH/2, 480)
        analysis_summary = [
            "Pada data yang terdistribusi seragam, Interpolation Search menang telak.", 
            "Namun, jika data tidak seragam, tebakannya akan sering salah,", 
            "dan performanya bisa lebih buruk dari Binary Search."
        ]
        for i, line in enumerate(analysis_summary): 
            draw_text(line, analysis_text_font, WHITE, surface, SCREEN_WIDTH/2, 530 + i * 30)
            

class SortingBattle:
    def _init_(self, animation_on):
        self.animation_on = animation_on
        self.num_bars = 500 if not self.animation_on else 100
        self.max_val = 500
        self.turbo_mode = False
        self.steps_per_frame = 30
        self.selected_button_index = 0
        
        margin = 50
        gap = 40
        arena_height = 480
        arena_width = (SCREEN_WIDTH - (2 * margin) - gap) / 2
        
        self.arena1_rect = pygame.Rect(margin, 80, int(arena_width), arena_height)
        self.arena2_rect = pygame.Rect(margin + int(arena_width) + gap, 80, int(arena_width), arena_height)
        
        # Define buttons di init agar konsisten
        self.y_pos = 670
        self.button_data1 = pygame.Rect(20, self.y_pos, 160, 40)
        self.button_data2 = pygame.Rect(190, self.y_pos, 160, 40)
        self.button_start = pygame.Rect(SCREEN_WIDTH // 2 - 80, self.y_pos, 160, 40)
        self.button_back = pygame.Rect(SCREEN_WIDTH - 180, self.y_pos, 160, 40)
        self.button_to_analysis = pygame.Rect(SCREEN_WIDTH - 220, 20, 200, 40)
        
        if self.animation_on:
            self.button_turbo = pygame.Rect(SCREEN_WIDTH // 2 + 90, self.y_pos, 160, 40)
        
        self.battle_results = {}
        self.go_to_analysis = False
        self.reset_battle()

    def reset_battle(self, data_type='random'):
        if data_type == 'random':
            self.array1 = generate_random_array(self.num_bars, 10, self.max_val)
        else:
            self.array1 = generate_sorted_array(self.num_bars, 10, self.max_val)
        
        self.array2 = self.array1.copy()
        self.sorting = False
        self.start_time = 0
        self.merge_sorter = None
        self.quick_sorter = None
        self.active_indices1 = {}
        self.active_indices2 = {}
        self.merge_steps = 0
        self.quick_steps = 0
        self.merge_sort_time = 0
        self.quick_sort_time = 0
        self.merge_finished = False
        self.quick_finished = False
        self.go_to_analysis = False

    def handle_events(self, events):
        mx, my = pygame.mouse.get_pos()
        
        # Gunakan buttons yang sudah didefinisikan di init
        self.bottom_buttons = [self.button_data1, self.button_data2, self.button_start]
        if self.animation_on:
            self.bottom_buttons.append(self.button_turbo)
        self.bottom_buttons.append(self.button_back)
        
        # Hover detection - RESET DULU
        self.selected_button_index = -1
        for i, button in enumerate(self.bottom_buttons):
            if button.collidepoint((mx, my)):
                self.selected_button_index = i

        for event in events:
            if not self.sorting:
                # Keyboard navigation
                if event.type == pygame.KEYDOWN:
                    if event.key in [pygame.K_RIGHT, pygame.K_DOWN]:
                        self.selected_button_index = (self.selected_button_index + 1) % len(self.bottom_buttons)
                    elif event.key in [pygame.K_LEFT, pygame.K_UP]:
                        self.selected_button_index = (self.selected_button_index - 1 + len(self.bottom_buttons)) % len(self.bottom_buttons)
                    elif event.key == pygame.K_RETURN:
                        btn = self.bottom_buttons[self.selected_button_index]
                        if btn == self.button_data1:
                            self.reset_battle('random')
                        elif btn == self.button_data2:
                            self.reset_battle('sorted')
                        elif btn == self.button_start:
                            self.sorting = True
                        elif self.animation_on and btn == self.button_turbo:
                            self.turbo_mode = not self.turbo_mode
                        elif btn == self.button_back:
                            return 'sorting_mode_selection'

                # Mouse clicks
                elif event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
                    if self.button_data1.collidepoint((mx, my)):
                        self.reset_battle('random')
                    elif self.button_data2.collidepoint((mx, my)):
                        self.reset_battle('sorted')
                    elif self.button_start.collidepoint((mx, my)):
                        self.sorting = True
                    elif self.animation_on and self.button_turbo.collidepoint((mx, my)):
                        self.turbo_mode = not self.turbo_mode
                    elif self.button_back.collidepoint((mx, my)):
                        return 'sorting_mode_selection'

            # Tombol analisis (setelah sorting selesai)
            if self.merge_finished and self.quick_finished:
                if (event.type == pygame.MOUSEBUTTONDOWN and event.button == 1 and 
                    self.button_to_analysis.collidepoint((mx, my))):
                    self.battle_results = {
                        "merge_time": self.merge_sort_time,
                        "quick_time": self.quick_sort_time
                    }
                    self.go_to_analysis = True

                elif event.type == pygame.KEYDOWN and event.key == pygame.K_RETURN:
                    self.battle_results = {
                        "merge_time": self.merge_sort_time,
                        "quick_time": self.quick_sort_time
                    }
                    self.go_to_analysis = True

        return None

    def update_logic(self):
        if not self.sorting:
            return

        if self.animation_on:
            if self.merge_sorter is None:
                self.start_time = pygame.time.get_ticks()
                self.merge_sorter = merge_sort_generator(self.array1, 0, len(self.array1))
                self.quick_sorter = quick_sort_generator(self.array2, 0, len(self.array2) - 1)
            
            steps = self.steps_per_frame if self.turbo_mode else 1
            for _ in range(steps):
                if not self.merge_finished:
                    try:
                        self.array1, self.active_indices1 = next(self.merge_sorter)
                        self.merge_steps += 1
                    except StopIteration:
                        self.merge_finished = True
                        self.merge_sort_time = max(self.merge_sort_time, (pygame.time.get_ticks() - self.start_time) / 1000.0)
                
                if not self.quick_finished:
                    try:
                        self.array2, self.active_indices2 = next(self.quick_sorter)
                        self.quick_steps += 1
                    except StopIteration:
                        self.quick_finished = True
                        self.quick_sort_time = max(self.quick_sort_time, (pygame.time.get_ticks() - self.start_time) / 1000.0)
        else:
            # Mode instant - KEDUA ALGORITMA HARUS DIEKSEKUSI
            if not self.merge_finished:
                s1 = time.perf_counter()
                merge_sort_standard(self.array1)
                e1 = time.perf_counter()
                self.merge_sort_time = e1 - s1
                self.merge_finished = True
                self.merge_steps = "N/A"

            if not self.quick_finished:
                s2 = time.perf_counter()
                quick_sort_standard(self.array2, 0, len(self.array2) - 1)
                e2 = time.perf_counter()
                self.quick_sort_time = e2 - s2
                self.quick_finished = True
                self.quick_steps = "N/A"

        if self.merge_finished and self.quick_finished:
            self.sorting = False

    def draw(self, surface, bg):
        surface.fill(PURPLE_BG)
        
        # Gambar background animasi
        bg.update_and_draw(surface)
        
        # Judul arena
        draw_text("Merge Sort", arena_font, WHITE, surface, self.arena1_rect.centerx, 50)
        draw_text("Quick Sort", arena_font, WHITE, surface, self.arena2_rect.centerx, 50)
        
        # Gambar arena
        pygame.draw.rect(surface, MAGENTA_NEON, self.arena1_rect, 3, border_radius=10)
        pygame.draw.rect(surface, MAGENTA_NEON, self.arena2_rect, 3, border_radius=10)
        
        # Gambar bars
        draw_bars(surface, self.array1, self.arena1_rect.x, self.arena1_rect.y, 
                 self.arena1_rect.width, self.arena1_rect.height, self.max_val, 
                 self.active_indices1, BLUE if self.merge_finished else None)
        draw_bars(surface, self.array2, self.arena2_rect.x, self.arena2_rect.y, 
                 self.arena2_rect.width, self.arena2_rect.height, self.max_val, 
                 self.active_indices2, BLUE if self.quick_finished else None)
        
        # Scoreboard
        score_y = 580
        draw_text("Time (s)", small_font, WHITE, surface, SCREEN_WIDTH / 2, score_y)
        draw_text(f"{self.merge_sort_time:.3f}", small_font, 
                 WHITE if self.merge_finished else GREY, 
                 surface, self.arena1_rect.centerx, score_y + 25)
        draw_text(f"{self.quick_sort_time:.3f}", small_font, 
                 WHITE if self.quick_finished else GREY, 
                 surface, self.arena2_rect.centerx, score_y + 25)
        
        draw_text("Anim Steps", small_font, WHITE, surface, SCREEN_WIDTH / 2, score_y + 55)
        draw_text(str(self.merge_steps), small_font, WHITE, 
                 surface, self.arena1_rect.centerx, score_y + 80)
        draw_text(str(self.quick_steps), small_font, WHITE, 
                 surface, self.arena2_rect.centerx, score_y + 80)
        
        # Tombol analisis (muncul setelah sorting selesai)
        if self.merge_finished and self.quick_finished:
            pygame.draw.rect(surface, MAGENTA_NEON, self.button_to_analysis, 3, border_radius=10)
            draw_text("Lihat Analisis ->", smaller_font, WHITE, 
                     surface, self.button_to_analysis.centerx, self.button_to_analysis.centery)
        
        # Gambar buttons menggunakan yang sudah didefinisikan di init
        bottom_buttons = [self.button_data1, self.button_data2, self.button_start]
        if self.animation_on:
            bottom_buttons.append(self.button_turbo)
        bottom_buttons.append(self.button_back)
        
        button_texts = ["Data Acak", "Data Terurut", "Start"]
        if self.animation_on:
            button_texts.append("Turbo: ON" if self.turbo_mode else "Turbo: OFF")
        button_texts.append("Back")
        
        # Gambar semua buttons
        for i, btn in enumerate(bottom_buttons):
            # Warna button: kuning jika dipilih dan tidak sedang sorting, magenta untuk lainnya
            color = YELLOW_NEON if (i == self.selected_button_index and not self.sorting) else MAGENTA_NEON
            pygame.draw.rect(surface, color, btn, 3, border_radius=10)
            draw_text(button_texts[i], smaller_font, WHITE, surface, btn.centerx, btn.centery)

    def run(self, surface, events, bg):
        next_state = self.handle_events(events)
        self.update_logic()
        self.draw(surface, bg)
        if self.go_to_analysis:
            return 'sorting_analysis'
        return next_state

class SearchingRace:
    def _init_(self, animation_on):
        self.animation_on = animation_on
        self.num_elements = 150 if self.animation_on else 250
        self.min_val = 0
        self.max_val = 1000
        margin = 50
        gap = 40
        arena_height = 250
        self.arena1_rect = pygame.Rect(margin, 120, SCREEN_WIDTH - (2*margin), arena_height)
        self.arena2_rect = pygame.Rect(margin, 120 + arena_height + gap, SCREEN_WIDTH - (2*margin), arena_height)
        self.battle_results = {}
        self.go_to_analysis = False
        self.winner = None
        self.selected_button_index = 0
        
        # Timer animasi
        self.anim_timer_event = pygame.USEREVENT + 1
        self.anim_delay = 750  # ms antara setiap step animasi
        if self.animation_on:
            pygame.time.set_timer(self.anim_timer_event, self.anim_delay)
        
        self.reset_race()

    def reset_race(self, data_type='uniform'):
        self.winner = None
        if data_type == 'uniform': 
            self.array = generate_sorted_array(self.num_elements, self.min_val, self.max_val, 'uniform')
        else: 
            self.array = generate_sorted_array(self.num_elements, self.min_val, self.max_val, 'skewed')
        
        if not self.array: 
            self.target = -1
        else: 
            self.target = random.choice(self.array)
        
        self.searching = False
        self.start_time = 0
        
        # Reset semua state animasi
        self.binary_searcher = None
        self.inter_searcher = None
        self.binary_state = {}
        self.inter_state = {}
        self.binary_steps = 0
        self.inter_steps = 0
        self.binary_time = 0.0
        self.inter_time = 0.0
        self.binary_finished = False
        self.inter_finished = False
        self.binary_found_idx = -1
        self.inter_found_idx = -1
        self.go_to_analysis = False

    def handle_events(self, events):
        mx, my = pygame.mouse.get_pos()
        y_pos = 670
        self.button_data1 = pygame.Rect(20, y_pos, 200, 40)
        self.button_data2 = pygame.Rect(230, y_pos, 200, 40)
        self.button_start = pygame.Rect(SCREEN_WIDTH//2 - 100, y_pos, 200, 40)
        self.button_back = pygame.Rect(SCREEN_WIDTH - 220, y_pos, 200, 40)
        self.button_to_analysis = pygame.Rect(SCREEN_WIDTH - 220, 20, 200, 40)

        self.buttons = [self.button_data1, self.button_data2, self.button_start, self.button_back]

        # Hover detection
        self.selected_button_index = -1
        for i, button in enumerate(self.buttons):
            if button.collidepoint((mx, my)):
                self.selected_button_index = i

        for event in events:
            # Handle animasi timer
            if self.animation_on and self.searching and event.type == self.anim_timer_event:
                self.advance_anim_step()
                continue

            if not self.searching:
                # Keyboard navigation
                if event.type == pygame.KEYDOWN:
                    if event.key in [pygame.K_RIGHT, pygame.K_DOWN]:
                        self.selected_button_index = (self.selected_button_index + 1) % len(self.buttons)
                    elif event.key in [pygame.K_LEFT, pygame.K_UP]:
                        self.selected_button_index = (self.selected_button_index - 1 + len(self.buttons)) % len(self.buttons)
                    elif event.key == pygame.K_RETURN:
                        btn = self.buttons[self.selected_button_index]
                        if btn == self.button_data1:
                            self.reset_race('uniform')
                        elif btn == self.button_data2:
                            self.reset_race('skewed')
                        elif btn == self.button_start:
                            self.start_search()
                        elif btn == self.button_back:
                            return 'searching_mode_selection'

                # Mouse clicks
                elif event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
                    if self.button_data1.collidepoint(event.pos):
                        self.reset_race('uniform')
                    elif self.button_data2.collidepoint(event.pos):
                        self.reset_race('skewed')
                    elif self.button_start.collidepoint(event.pos):
                        self.start_search()
                    elif self.button_back.collidepoint(event.pos):
                        return 'searching_mode_selection'

            # Tombol analisis
            if self.binary_finished and self.inter_finished:
                if event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
                    if self.button_to_analysis.collidepoint(event.pos):
                        self.go_to_analysis = True

                elif event.type == pygame.KEYDOWN and event.key == pygame.K_RETURN:
                    self.go_to_analysis = True

        return None

    def start_search(self):
        """Function untuk memulai pencarian"""
        self.searching = True
        self.start_time = pygame.time.get_ticks()
        
        # Inisialisasi generator untuk mode animasi
        if self.animation_on:
            self.binary_searcher = binary_search_generator(self.array, self.target)
            self.inter_searcher = interpolation_search_generator(self.array, self.target)
        else:
            # Untuk mode instant, langsung eksekusi
            self.update_logic()

    def advance_anim_step(self):
        """Logic untuk maju satu step animasi"""
        if not self.searching:
            return

        # Binary Search
        if not self.binary_finished and self.binary_searcher:
            try:
                self.binary_steps, range_info, probe_idx, found_idx = next(self.binary_searcher)
                self.binary_state = {'range': range_info, 'probe': probe_idx}
                
                if found_idx != -1:
                    self.binary_found_idx = found_idx
                    self.binary_finished = True
                    self.binary_time = (pygame.time.get_ticks() - self.start_time) / 1000.0
                    self.check_winner('Binary')
            except StopIteration:
                self.binary_finished = True

        # Interpolation Search  
        if not self.inter_finished and self.inter_searcher:
            try:
                self.inter_steps, range_info, probe_idx, found_idx = next(self.inter_searcher)
                self.inter_state = {'range': range_info, 'probe': probe_idx}
                
                if found_idx != -1:
                    self.inter_found_idx = found_idx
                    self.inter_finished = True
                    self.inter_time = (pygame.time.get_ticks() - self.start_time) / 1000.0
                    self.check_winner('Interpolation')
            except StopIteration:
                self.inter_finished = True

        # Cek jika keduanya selesai
        if self.binary_finished and self.inter_finished:
            self.searching = False
            # Pastikan waktu dihitung untuk yang belum selesai
            if self.binary_time == 0:
                self.binary_time = (pygame.time.get_ticks() - self.start_time) / 1000.0
            if self.inter_time == 0:
                self.inter_time = (pygame.time.get_ticks() - self.start_time) / 1000.0

    def update_logic(self):
        """Update logic untuk mode instant"""
        if not self.searching or self.animation_on:
            return

        # Mode instant - eksekusi langsung
        if not self.binary_finished:
            start_time = time.perf_counter()
            self.binary_found_idx, self.binary_steps = binary_search_standard(self.array, self.target)
            end_time = time.perf_counter()
            self.binary_time = end_time - start_time
            self.binary_finished = True
            self.check_winner('Binary')

        if not self.inter_finished:
            start_time = time.perf_counter()
            self.inter_found_idx, self.inter_steps = interpolation_search_standard(self.array, self.target)
            end_time = time.perf_counter()
            self.inter_time = end_time - start_time
            self.inter_finished = True
            self.check_winner('Interpolation')

        if self.binary_finished and self.inter_finished:
            self.searching = False

    def check_winner(self, algo_name):
        """Tentukan pemenang berdasarkan waktu tercepat"""
        if self.winner is None:
            self.winner = algo_name
        else:
            # Jika kedua algoritma sudah selesai, bandingkan waktu
            if self.binary_finished and self.inter_finished:
                if self.binary_time < self.inter_time:
                    self.winner = "Binary"
                elif self.inter_time < self.binary_time:
                    self.winner = "Interpolation"
                else:
                    self.winner = "Seri!"

    def draw(self, surface, bg):
        bg.update_and_draw(surface)
        draw_text("Balapan Searching", title_font, WHITE, surface, SCREEN_WIDTH/2, 50)
        draw_text(f"Mencari Angka: {self.target}", arena_font, YELLOW_NEON, surface, SCREEN_WIDTH/2, 90)
        
        # Gambar arena dengan state yang benar
        self.draw_search_arena(surface, self.arena1_rect, "Binary Search", self.binary_state, self.binary_found_idx, self.binary_finished)
        self.draw_search_arena(surface, self.arena2_rect, "Interpolation Search", self.inter_state, self.inter_found_idx, self.inter_finished)
        
        self.draw_scoreboard(surface)
        
        # Gambar tombol
        if not self.searching:
            for i, btn in enumerate(self.buttons):
                color = YELLOW_NEON if i == self.selected_button_index else MAGENTA_NEON
                pygame.draw.rect(surface, color, btn, 3, border_radius=15)
            
            draw_text("Data Seragam", smaller_font, WHITE, surface, self.button_data1.centerx, self.button_data1.centery)
            draw_text("Data Tdk Seragam", smaller_font, WHITE, surface, self.button_data2.centerx, self.button_data2.centery)
            draw_text("Start", smaller_font, WHITE, surface, self.button_start.centerx, self.button_start.centery)
            draw_text("Kembali", smaller_font, WHITE, surface, self.button_back.centerx, self.button_back.centery)
        
        # Tombol analisis dan pemenang
        if self.binary_finished and self.inter_finished:
            pygame.draw.rect(surface, MAGENTA_NEON, self.button_to_analysis, 3, border_radius=10)
            draw_text("Lihat Analisis ->", small_font, WHITE, surface, self.button_to_analysis.centerx, self.button_to_analysis.centery)
            
            if self.winner:
                winner_color = MAGENTA_NEON if "Binary" in self.winner else CYAN_NEON
                draw_text(f"{self.winner} WINS!", winner_font, winner_color, surface, SCREEN_WIDTH/2, self.arena1_rect.bottom + (self.arena2_rect.top - self.arena1_rect.bottom)/2)

    def draw_search_arena(self, surface, rect, name, state, found_idx, is_finished):
        pygame.draw.rect(surface, BLACK, rect)
        pygame.draw.rect(surface, MAGENTA_NEON if "Binary" in name else CYAN_NEON, rect, 3, border_radius=10)
        draw_search_grid(surface, self.array, rect, state, found_idx, is_finished)

    def draw_scoreboard(self, surface):
        score_y = self.arena2_rect.bottom + 20
        draw_text("Binary Search", small_font, MAGENTA_NEON, surface, SCREEN_WIDTH * 0.25, score_y)
        draw_text("Interpolation Search", small_font, CYAN_NEON, surface, SCREEN_WIDTH * 0.75, score_y)
        draw_text(f"{self.binary_time:.4f} s", small_font, WHITE, surface, SCREEN_WIDTH * 0.25, score_y + 30)
        draw_text(f"{self.inter_time:.4f} s", small_font, WHITE, surface, SCREEN_WIDTH * 0.75, score_y + 30)
        draw_text(f"{self.binary_steps} probes", small_font, WHITE, surface, SCREEN_WIDTH * 0.25, score_y + 60)
        draw_text(f"{self.inter_steps} probes", small_font, WHITE, surface, SCREEN_WIDTH * 0.75, score_y + 60)

    def run(self, screen, events, animated_bg):
        next_state = self.handle_events(events)
        
        # Update logic untuk mode instant
        self.update_logic()
        
        self.draw(screen, animated_bg)
        
        if self.go_to_analysis:
            self.battle_results = {
                "binary_time": self.binary_time,
                "inter_time": self.inter_time,
                "binary_steps": self.binary_steps,
                "inter_steps": self.inter_steps
            }
            return 'searching_analysis'
            
        return next_state

        
# ===============================================================
# KONTROLER UTAMA PROGRAM (FINAL)
# ===============================================================
def main():
    screens = {
        'main_menu': MainMenu(), 'credits': CreditsScreen(), 'selection': SelectionMenu(),
        'sorting_mode_selection': SortingModeSelection(),
        'searching_mode_selection': SearchingModeSelection(),
        'sorting_battle_animated': SortingBattle(animation_on=True),
        'sorting_battle_instant': SortingBattle(animation_on=False),
        'searching_race_animated': SearchingRace(animation_on=True),
        'searching_race_instant': SearchingRace(animation_on=False),
        'sorting_analysis': AnalysisScreen(is_sorting=True),
        'searching_analysis': AnalysisScreen(is_sorting=False),
    }
    game_state = 'main_menu'
    animated_bg = AnimatedBackground()
    last_battle_state = 'sorting_battle_animated'
    battle_results = {}
    
    while True:
        events = pygame.event.get()
        for event in events:
            if event.type == pygame.QUIT: 
                pygame.quit()
                sys.exit()
        
        screen.fill(PURPLE_BG)
        active_screen = screens[game_state]
        
        if 'analysis' in game_state: 
            next_state = active_screen.run(screen, events, animated_bg, battle_results)
        else: 
            next_state = active_screen.run(screen, events, animated_bg)
        
        if next_state == 'quit': 
            pygame.quit()
            sys.exit()
        
# ===============================================================
# INI KODE BARU YANG SUDAH DIPERBAIKI
# ===============================================================
        # 1. Handle state-state khusus dulu (transisi ke analisis, atau kembali dari analisis)
        if game_state.startswith('sorting_battle'):
            last_battle_state = game_state
            if hasattr(active_screen, 'go_to_analysis') and active_screen.go_to_analysis:
                battle_results = active_screen.battle_results
                next_state = 'sorting_analysis'  # Gunakan next_state untuk ganti
                active_screen.go_to_analysis = False
        
        elif game_state.startswith('searching_race'):
            last_battle_state = game_state
            if hasattr(active_screen, 'go_to_analysis') and active_screen.go_to_analysis:
                battle_results = active_screen.battle_results
                next_state = 'searching_analysis' # Gunakan next_state untuk ganti
                active_screen.go_to_analysis = False
        
        elif 'analysis' in game_state and next_state == 'back_to_battle':
            # Jika kembali dari analisis, reset arena dan batalkan transisi lain
            game_state = last_battle_state
            if game_state.startswith('searching_race'):
                screens[game_state].reset_race()
            else:
                screens[game_state].reset_battle()
            next_state = None # Penting: batalkan next_state agar tidak diproses lagi

        # 2. Setelah itu, eksekusi SEMUA permintaan pindah layar (next_state)
        if next_state:
            game_state = next_state
        
        pygame.display.update()
        clock.tick(60)

if __name__ == '_main_':
    main()