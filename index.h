<!DOCTYPE html>
<html lang="ku" dir="rtl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>پڕۆژەیا ئیسلامی - مەسروور</title>
    <style>
        :root { --main-color: #27ae60; --dark-bg: #121212; --card-bg: #1e272e; }
        body { font-family: 'Tahoma', sans-serif; background: var(--dark-bg); color: white; margin: 0; text-align: center; }
        .page { display: none; padding: 20px; animation: fadeIn 0.4s; }
        .active { display: block; }
        @keyframes fadeIn { from { opacity: 0; } to { opacity: 1; } }
        .btn-lang { display: block; width: 85%; padding: 20px; margin: 20px auto; background: var(--main-color); color: white; border-radius: 15px; font-size: 22px; font-weight: bold; border: none; cursor: pointer; }
        .grid { display: grid; grid-template-columns: 1fr 1fr; gap: 15px; padding: 10px; }
        .card { background: var(--card-bg); padding: 25px; border-radius: 15px; cursor: pointer; font-weight: bold; border: 1px solid #333; }
        .list-container { height: 65vh; overflow-y: auto; background: #181818; padding: 15px; border-radius: 12px; text-align: right; border: 1px solid #333; }
        .item-row { background: #252e35; padding: 15px; margin-bottom: 10px; border-radius: 8px; border-right: 5px solid var(--main-color); cursor: pointer; }
        #ayah-content { background: white; color: black; padding: 25px; border-radius: 12px; line-height: 2.2; font-size: 20px; text-align: justify; }
        #qibla-arrow { font-size: 100px; margin: 30px 0; display: inline-block; transition: 0.1s; color: var(--main-color); }
        .back-btn { background: #e74c3c; color: white; border: none; padding: 10px 20px; border-radius: 8px; margin-bottom: 15px; cursor: pointer; }
    </style>
</head>
<body>

    <div id="lang-page" class="page active">
        <h1 style="color: var(--main-color); margin-top: 80px;">ب خێر بێی بۆ سایتێ ئیسلامی</h1>
        <button class="btn-lang" onclick="showPage('main-page')">بادینی (Badini)</button>
        <button class="btn-lang" onclick="showPage('main-page')">سۆرانی (Sorani)</button>
    </div>

    <div id="main-page" class="page">
        <h2 style="color: var(--main-color);">مینیویا سەرەکی</h2>
        <div class="grid">
            <div class="card" onclick="showPage('quran-page')">📖 قورعان</div>
            <div class="card" onclick="showPage('dua-page')">🤲 دوعا</div>
            <div class="card" onclick="showPage('qibla-page')">🕋 قیبلە</div>
            <div class="card" onclick="showPage('farmuda-page')">📜 فەرموودە</div>
            <div class="card" onclick="showPage('werd-page')">✨ وێرد</div>
        </div>
    </div>

    <div id="quran-page" class="page">
        <button class="back-btn" onclick="showPage('main-page')">⬅ پاش</button>
        <div class="list-container" id="quran-list"></div>
    </div>

    <div id="ayah-page" class="page">
        <button class="back-btn" onclick="showPage('quran-page')">⬅ پاش</button>
        <h2 id="surah-title" style="color: var(--main-color);"></h2>
        <div id="ayah-content">چاوەڕێ بکە...</div>
    </div>

    <div id="dua-page" class="page">
        <button class="back-btn" onclick="showPage('main-page')">⬅ پاش</button>
        <h3>🤲 دوعایێن پێغەمبەری (س.خ)</h3>
        <div class="list-container" id="dua-list"></div>
    </div>

    <div id="qibla-page" class="page">
        <button class="back-btn" onclick="showPage('main-page')">⬅ پاش</button>
        <div id="qibla-arrow">⬆</div>
        <p>مۆبایلا خۆ ڕاست دابنێ دا قیبلەیێ ببینی</p>
    </div>

    <div id="farmuda-page" class="page">
        <button class="back-btn" onclick="showPage('main-page')">⬅ پاش</button>
        <h3>📜 فەرموودەیێن پێغەمبەری</h3>
        <div class="list-container" id="farmuda-list"></div>
    </div>
    <div id="werd-page" class="page">
        <button class="back-btn" onclick="showPage('main-page')">⬅ پاش</button>
        <h3>✨ وێردێن سپێدە و ئێڤاری</h3>
        <div class="list-container" id="werd-list"></div>
    </div>

    <script>
        // فۆنکشنا گوهۆڕینا لاپەران
        function showPage(id) {
            document.querySelectorAll('.page').forEach(p => p.classList.remove('active'));
            const targetPage = document.getElementById(id);
            if (targetPage) targetPage.classList.add('active');
        }

        // بارکرنا ١١٤ سوورەتان
        const surahs = ["الفاتحة", "البقرة", "آل عمران", "النساء", "المائدة", "الأنعام", "الأعراف", "الأنفال", "التوبة", "يونس", "هود", "يوسف", "الرعد", "إبراهيم", "الحجر", "النحل", "الإسراء", "الكهف", "مريم", "طه", "الأنبياء", "الحج", "المؤمنون", "النور", "الفرقان", "الشعراء", "النمل", "القصص", "العنكبوت", "الروم", "لقمان", "السجدة", "الأحزاب", "سبأ", "فاطر", "يس", "الصافات", "ص", "الزمر", "غافر", "فصلت", "الشورى", "الزخرف", "الدخان", "الجاثية", "الأحقاف", "محمد", "الفتح", "الحجرات", "ق", "الذاريات", "الطور", "النجم", "القمر", "الرحمن", "الواقعة", "الحديد", "المجادلة", "الحشر", "الممتحنة", "الصف", "الجمعة", "المنافقون", "التغابن", "الطلاق", "التحريم", "الملك", "القلم", "الحاقة", "المعارج", "نوح", "الجن", "المزمل", "المدثر", "القيامة", "الإنسان", "المرسلات", "النبأ", "النازعات", "عبس", "التكوير", "الانفطار", "المطففين", "الانشقاق", "البروج", "الطارق", "الأعلى", "الغاشية", "الفجر", "البلد", "الشمس", "الليل", "الضحى", "الشرح", "التين", "العلق", "القدر", "البينة", "الزلزلة", "العاديات", "القارعة", "التكاثر", "العصر", "الهمزة", "الفيل", "قريش", "الماعون", "الكوثر", "الكافرون", "النصر", "المسد", "الإخلاص", "الفلق", "الناس"];
        const qList = document.getElementById('quran-list');
        surahs.forEach((name, i) => {
            qList.innerHTML += `<div class="item-row" onclick="loadAyahs(${i+1}, '${name}')">${i+1}. سورەتێ ${name}</div>`;
        });

        async function loadAyahs(id, name) {
            showPage('ayah-page');
            document.getElementById('surah-title').innerText = name;
            document.getElementById('ayah-content').innerText = "بارکرنا ئایەتان...";
            try {
                const res = await fetch(`https://api.alquran.cloud/v1/surah/${id}`);
                const data = await res.json();
                document.getElementById('ayah-content').innerHTML = data.data.ayahs.map(a => a.text + ` <span style="color:green">(${a.numberInSurah})</span>`).join(" ");
            } catch {
                document.getElementById('ayah-content').innerText = "پێویستت ب ئینتەرنێتێ هەیە بۆ خویندنا ئایەتان!";
            }
        }

        // بارکرنا دوعا، فەرموودە و وێردان
        const duas = ["اللَّهُمَّ إِنَّكَ عَفُوٌّ تُحِبُّ الْعَفْوَ فَاعْفُ عَنِّي", "رَبَّنَا آتِنَا فِي الدُّنْيَا حَسَنَةً وَفِي الْآخِرَةِ حَسَنَةً", "لا إله إلا أنت سبحانك إني كنت من الظالمين", "اللهم صل على محمد", "أستغفر الله العظيم", "حسبنا الله ونعم الوكيل"];
        const dList = document.getElementById('dua-list');
        duas.forEach(d => { dList.innerHTML += `<div class="item-row">🤲 ${d}</div>`; });

        const farmudas = ["قَالَ رَسُولُ اللَّهِ ﷺ: (بَلِّغُوا عَنِّي وَلَوْ آيَةً)", "قَالَ ﷺ: (خَيْرُكُمْ مَنْ تَعَلَّمَ الْقُرْآنَ وَعَلَّمَهُ)"];
        const fList = document.getElementById('farmuda-list');
        farmudas.forEach(f => { fList.innerHTML += `<div class="item-row">📜 ${f}</div>`; });

        const werds = ["أعوذ بكلمات الله التامات من شر ما خلق", "بسم الله الذي لا يضر مع اسمه شيء"];
        const wList = document.getElementById('werd-list');
        werds.forEach(w => { wList.innerHTML += `<div class="item-row">✨ ${w}</div>`; });

        // قیبلە
        window.addEventListener('deviceorientation', (e) => {
            if(e.alpha) document.getElementById('qibla-arrow').style.transform = `rotate(${360 - e.alpha}deg)`;
        });
    </script>
</body>
</html>
